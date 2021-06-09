//
// Created by alexa on 12/01/2021.
//

#include <regex>
#include "TagValidation.h"

void TagValidation::validateAggOpenTag(const std::string &openTag) {
    std::regex aggregateOpenTagValidator(AGG_OPENING_TAG_VALIDATOR);
    if (!regex_match(openTag, aggregateOpenTagValidator)) {
        throw ERROR_INVALID_AGG_OPENING_TAG;
    }
}

void TagValidation::validateMapOpenTag(const std::string &openTag) {
    std::regex mapOpenTagValidator(MAP_OPENING_TAG_VALIDATOR);
    if (!regex_match(openTag, mapOpenTagValidator))
        throw ERROR_INVALID_MAP_OPENING_TAG;
}

void TagValidation::validateSrtOpenTag(const std::string &openTag) {
    std::regex srtOpenTagValidator(SORT_OPENING_TAG_VALIDATOR);
    if (!regex_match(openTag, srtOpenTagValidator))
        throw ERROR_INVALID_SRT_OPENING_TAG;
}

void TagValidation::validateMappingTagAttribute(const std::string &attribute) {
    std::regex attributeValidator(TAG_ATTRIBUTE_VALIDATOR);
    if (!regex_match(attribute, attributeValidator)) {
        throw ERROR_INVALID_MAPPING_TAG_ATTR;
    }
}

void TagValidation::validateCloseTag(const std::string &openTag, std::string &closeTag) {
    std::string tempClosingTag = closeTag;

    std::regex aggregateOpenTagValidator(AGG_OPENING_TAG_VALIDATOR);
    std::regex mapOpenTagValidator(MAP_OPENING_TAG_VALIDATOR);
    std::regex srtOpenTagValidator(SORT_OPENING_TAG_VALIDATOR);

    std::regex srtOrderedOpenTagValidator(SRT_ORD_TAG_VALIDATOR);
    std::regex srtSubListOpenTagValidator(SRT_SLC_TAG_VALIDATOR);

    tempClosingTag.erase(1, 1);

    // AGG_OPENING_CLOSING_TAG VALIDATION
    if (regex_match(openTag, aggregateOpenTagValidator)) {
        if (openTag != tempClosingTag)
            throw ERROR_INVALID_AGGREGATING_CLOSING_TAG_MESSAGE;
    }

    // MAP_OPENING_CLOSING_TAG VALIDATION
    if (regex_match(openTag, mapOpenTagValidator)) {
        std::string tmp = IMLParser::getTagWithoutAttribute(openTag);
        if (tmp != tempClosingTag)
            throw ERROR_INVALID_MAPPING_CLOSING_TAG_MESSAGE;
    }

    // SRT_OPENING_CLOSING_TAG VALIDATION <SRT-SLC "1"> <SRT-ORD "ASC"> </SRT-ORD> <SRT-REV> </SRT-REV>
    if (regex_match(openTag, srtOpenTagValidator)) {
            std::string tmpOpenTag = IMLParser::getTagWithoutAttribute(openTag);
            if (tmpOpenTag != tempClosingTag)
                throw ERROR_INVALID_SORTING_CLOSING_TAG_MESSAGE;
        }
}

void TagValidation::validateData(const std::string &data, size_t &index) {
    if ((data[index] >= 'a' && data[index] <= 'z') || (data[index] >= 'A' && data[index] <= 'Z')) {
        std::cout << "data[" << index << "] = " << data[index] << std::endl;
        throw ERROR_INVALID_DATA_MESSAGE;
    }
}