//
// Created by alexa on 04/12/2020.
//

#ifndef IML_IMLPARSER_H
#define IML_IMLPARSER_H

#include <stack>
#include "TagFactory.h"

class IMLParser {
public:
    explicit IMLParser(const std::string &inputPath, const std::string &outputPath);
    void extractOpenTag(const std::string &fileContent, std::string &openTag, std::string &mappingValue, size_t &index);


    void extractCloseTag(const std::string &fileContent, const std::string &currentOpenTag, std::string &currentCloseTag, std::vector<double> data, const std::string &currentAttribute, std::string &result, size_t &index);
    void extractTagData(std::string &fileContent, std::string &currentTagData, std::vector<double> &data, size_t &index);
    void extractTagAttribute(const std::string &fileContent, std::string &mappingValue, size_t &index);

    static void removeWhiteSpaces(std::string &content);
    static std::string readFile(const std::string &path);
    static void writeFile(const std::string &outputPath, const std::string &outputContent);

    static std::string getTagWithoutAttribute(std::string tag);
};


#endif //IML_IMLPARSER_H
