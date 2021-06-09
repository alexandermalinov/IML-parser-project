//
// Created by alexa on 02/12/2020.
//

#ifndef IML_MAPTAG_H
#define IML_MAPTAG_H

#include "vector"
#include "TagFactory.h"

class MapTag {
public:
    MapTag(const std::string &openTag, const std::string &closeTag, std::string &data, const double &value);

    const std::string &getOpenTag() const;
    void setOpenTag(const std::string &openTag);

    const std::string &getCloseTag() const;
    void setCloseTag(const std::string &closeTag);

    IMLAttributes::MappingOperations getOperation() const;
    void setOperation(IMLAttributes::MappingOperations attribute);

    std::string getData() const;
    void setData(const std::string &data);

    double getValue() const;
    void setValue(const double &value);

    static std::string increment(std::vector<double> &data, const std::string &mappingValue);
    static std::string multiply(std::vector<double> &data, const std::string &mappingValue);

    void printMapTag() const;

private:
    std::string openTag;
    std::string closeTag;
    std::string data;
    IMLAttributes::MappingOperations attribute;
    double mappingValue;
};

#endif //IML_MAPTAG_H
