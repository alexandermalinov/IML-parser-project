//
// Created by alexa on 12/01/2021.
//

#ifndef IML_TAGVALIDATION_H
#define IML_TAGVALIDATION_H

const char* TAG_ATTRIBUTE_VALIDATOR = "^([-+]?\\d+(\\.\\d+)?)|(ASC)|(DSC)$";

const char* AGG_OPENING_TAG_VALIDATOR  = "^((<AGG-SUM>)|(<AGG-PRO>)|(<AGG-AVG>)|(<AGG-FST>)|(<AGG-LST>)){1}$";
const char* MAP_OPENING_TAG_VALIDATOR  = "^(<MAP-MLT \">)|(<MAP-INC \">){1}$";
const char* SORT_OPENING_TAG_VALIDATOR = "^((<SRT-REV>)|(<SRT-DST>)|(<SRT-ORD \">)|(<SRT-SLC \">)){1}$";

const char* SRT_ORD_TAG_VALIDATOR = "^((<SRT-ORD\\s\">)|(<SRT-ORD\\s\">)){1}$";
const char* SRT_SLC_TAG_VALIDATOR = "^<SRT-SLC\\s\">$";



const char* ERROR_INVALID_DATA_MESSAGE = "Error. Invalid data!\n";

const char* ERROR_INVALID_SORTING_CLOSING_TAG_MESSAGE = "Error. Invalid sorting closing tag!\n";
const char* ERROR_INVALID_MAPPING_CLOSING_TAG_MESSAGE = "Error. Invalid mapping closing tag!\n";
const char* ERROR_INVALID_AGGREGATING_CLOSING_TAG_MESSAGE = "Error. Invalid aggregating closing tag!\n";

const char* ERROR_INVALID_MAPPING_TAG_ATTR = "Error. Invalid mapping tag attribute!\n";
const char* ERROR_INVALID_SRT_OPENING_TAG  = "Error. Invalid sorting opening tag!\n";
const char* ERROR_INVALID_MAP_OPENING_TAG  = "Error. Invalid mapping opening tag!\n";
const char* ERROR_INVALID_AGG_OPENING_TAG  = "Error. Invalid aggregating opening tag!\n";

class TagValidation {
public:
    static void validateMappingTagAttribute(const std::string &attribute);

    static void validateAggOpenTag(const std::string &openTag);
    static void validateMapOpenTag(const std::string &openTag);
    static void validateSrtOpenTag(const std::string &openTag);

    static void validateData(const std::string &data, size_t &index);

    static void validateCloseTag(const std::string &openTag, std::string &closeTag);
};


#endif //IML_TAGVALIDATION_H
