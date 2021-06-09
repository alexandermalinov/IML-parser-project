//
// Created by alexa on 03/12/2020.
//

#ifndef IML_TAGFACTORY_H
#define IML_TAGFACTORY_H

#include <iomanip>

class TagFactory {
public:
    static std::string calculateTags(const std::string &openTag, const std::string &closeTag, std::vector<double> &data, const std::string &attribute);

    static std::string extractTagType(const std::string &openTag);

    static std::string setTagOperation(const std::string &openTag);

    static IMLAttributes::AggregateOperations extractAggType(const std::string &openTag);
    static IMLAttributes::MappingOperations extractMapType(const std::string &openTag);
    static IMLAttributes::SortingOperations extractSortType(const std::string &openTag);

    static IMLAttributes::AggregateOperations getAggType(const std::string& type);
    static IMLAttributes::MappingOperations getMapType(const std::string& type);
    static IMLAttributes::SortingOperations getSortType(const std::string& type);
};


#endif //IML_TAGFACTORY_H
