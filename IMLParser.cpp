//
// Created by alexa on 04/12/2020.
//

#include <fstream>
#include <algorithm>
#include "TagValidation.h"
#include "IMLParser.h"
#include <regex>


IMLParser::IMLParser(const std::string &inputPath, const std::string &outputPath) {
    std::string fileContent = readFile(inputPath);
    removeWhiteSpaces(fileContent);

    std::vector<double> data;

    std::vector<std::string> openTag;
    std::vector<std::string> closeTag;

    std::string currentOpenTag;
    std::string currentCloseTag;
    std::string currentTagData;
    std::string currentAttribute;

    for (size_t i = 0; fileContent[i] != '\0'; i++) {
        size_t index = i;

        if (fileContent[index] == '<' && fileContent[index + 1] != '/') {
            // Clearing all temporarily data
            currentOpenTag.clear();
            currentCloseTag.clear();
            currentAttribute.clear();
            currentTagData.clear();
            data.clear();

            extractOpenTag(fileContent, currentOpenTag, currentAttribute, index);
            extractTagData(fileContent, currentTagData, data, index);

            std::string resultData;
            extractCloseTag(fileContent, currentOpenTag, currentCloseTag, data, currentAttribute, resultData, index);

            if (!currentCloseTag.empty()) {
                TagValidation::validateCloseTag(currentOpenTag, currentCloseTag);
                // Replacing the data in fileContent with calculated resultData data
                fileContent.replace(i, index - i, resultData);
                // The for loop sets i to 1 everytime after first iteration.
                // Setting i to -1 to avoid i being 1 in the for cycle
                i = -1;
            }
        }
    }
    std::cout << "\nResult from parsing " << inputPath << "\n" << fileContent << "\n";
    writeFile(outputPath, fileContent);
}

std::string IMLParser::readFile(const std::string &path) {
    std::ifstream fileReader(path);
    std::string buffer;
    std::string fileContent;

    if (fileReader.is_open()) {
        while (std::getline(fileReader, buffer)) {
            fileContent.append(buffer);
        }
    }
    fileReader.close();
    return fileContent;
}

void IMLParser::writeFile(const std::string &outputPath, const std::string &outputContent) {
    std::ofstream fileWriter(outputPath);
    if (fileWriter.is_open() && fileWriter.good()) {
        fileWriter << outputContent;
    }
    fileWriter.close();
}

void IMLParser::removeWhiteSpaces(std::string &content) {
    std::string temp;

    for (size_t i = 0; content[i] != '\0'; ++i) {
        /*
         * 1. Checking if the last element is '>'. If it is '>', begin iterating until white space is found.
         * E.g.   			81 3
         * 2. Iterating while '<' is found.
         * 3. If the current element is digit, point or minus-> push it.
         * 4. If the current element is white space, point or minus and the next element is digit -> push it.
         * 5. Iterate.
         * 6. Push all other elements which are not between '<' and '>' (between the tags).
         */
        if (content[i - 1] == '>') {
            // 1
            while (content[i] == ' ') {
                i++;
            }
            // 2
            while (content[i] != '<' && content[i] != '\0') {
                // Validating the current element
                TagValidation::validateData(content, i);
                // 3
                if ((content[i] >= '0' && content[i] <= '9') || content[i] == '.' || content[i] == '-') {
                    temp.push_back(content[i]);
                }
                // 4
                if (content[i] == ' ' &&
                    ((content[i + 1] >= '0' && content[i + 1] <= '9') || content[i] == '.' || content[i] == '-')) {
                    temp.push_back(content[i]);
                }
                // 5
                i++;
            }
        }
        // 6
        temp.push_back(content[i]);
    }
    content = temp;
}

void IMLParser::extractTagAttribute(const std::string &fileContent, std::string &mappingValue, size_t &index) {
    if (fileContent[index] == '\"') {
        index++;
        while (fileContent[index] != '\"') {
            mappingValue.push_back(fileContent[index]);
            index++;
        }
    }
}

void IMLParser::extractOpenTag(const std::string &fileContent, std::string &openTag, std::string &mappingValue,
                               size_t &index) {
    while (fileContent[index - 1] != '>') {
        extractTagAttribute(fileContent, mappingValue, index);
        openTag.push_back(fileContent[index]);
        index++;
    }
    //TODO if mapping value is empty throw exception!
    if (!mappingValue.empty())
        TagValidation::validateMappingTagAttribute(mappingValue);

    if (openTag[1] == 'A')
        TagValidation::validateAggOpenTag(openTag);
    else if (openTag[1] == 'S')
        TagValidation::validateSrtOpenTag(openTag);
    else if (openTag[1] == 'M')
        TagValidation::validateMapOpenTag(openTag);
    else
        throw "Invalid opening tag!\n";
}

void IMLParser::extractTagData(std::string &fileContent, std::string &currentTagData, std::vector<double> &data,
                               size_t &index) {
    if (fileContent[index - 1] == '>' && fileContent[index] == '<') {
        fileContent.insert(index, " ");
    } else {
        while ((fileContent[index] >= '0' && fileContent[index] <= '9') || fileContent[index] == ' ' ||
               fileContent[index] == '-' || fileContent[index] == '.') {
            // Creating nested while loop in purpose to divide string numbers into separated numbers
            // e.g. 13 18 23 without the nested loop all digits will be pushed as 131823
            while (fileContent[index] != ' ' &&
                   ((fileContent[index] >= '0' && fileContent[index] <= '9') || fileContent[index] == '-' ||
                    fileContent[index] == '.')) {
                currentTagData.push_back(fileContent[index]);
                index++;
            }
            // Pushing current number
            if (!currentTagData.empty()) {
                data.push_back(std::stod(currentTagData));
            }
            currentTagData.clear();
            // Incrementing index++ only if the current char is white space
            // in case to stop incrementing when closing tag is faced
            if (fileContent[index] == ' ')
                index++;
        }
    }
}

void IMLParser::extractCloseTag(const std::string &fileContent, const std::string &currentOpenTag,
                                std::string &currentCloseTag, std::vector<double> data,
                                const std::string &currentAttribute, std::string &result, size_t &index) {
    if (fileContent[index] == '<' && fileContent[index + 1] == '/') {
        // Assigning the result data calculated by the static method calculateTags
        result = TagFactory::calculateTags(currentOpenTag, currentCloseTag, data, currentAttribute);
        while (fileContent[index - 1] != '>') {
            currentCloseTag.push_back(fileContent[index]);
            index++;
        }
    }
}

std::string IMLParser::getTagWithoutAttribute(std::string tag) {
    std::string tmp;
    for (int j = 0; tag[j] != '\0'; j++) {
        if (tag[j] == ' ' || tag[j] == '\"')
            j++;
        else
            tmp.push_back(tag[j]);
    }
    return tmp;
}


