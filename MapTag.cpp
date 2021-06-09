//
// Created by alexa on 02/12/2020.
//

#include "MapTag.h"

MapTag::MapTag(const std::string &openTag, const std::string &closeTag, std::string &data , const double &value) {
    setOpenTag(openTag);
    setCloseTag(closeTag);
    setData(data);
    setValue(value);
}

const std::string &MapTag::getOpenTag() const {
    return openTag;
}

void MapTag::setOpenTag(const std::string &openTag) {
    if (openTag.empty()) {
        std::cout << "Empty opening tag.";
        return;
    } else {
        this->openTag = openTag;
    }
}

const std::string &MapTag::getCloseTag() const {
    return closeTag;
}

void MapTag::setCloseTag(const std::string &closeTag) {
    if (closeTag.empty()) {
        std::cout << "Empty closing tag.";
        return;
    } else {
        this->closeTag = closeTag;
    }
}

IMLAttributes::MappingOperations MapTag::getOperation() const {
    return attribute;
}

void MapTag::setOperation(IMLAttributes::MappingOperations attribute) {
    this->attribute = attribute;
}

std::string MapTag::getData() const {
    return data;
}

void MapTag::setData(const std::string &data) {
    for (const auto &i : data) {
        this->data.push_back(i);
    }
}

double MapTag::getValue() const {
    return mappingValue;
}

void MapTag::setValue(const double &value) {
    this->mappingValue = value;
}

std::string MapTag::increment(std::vector<double> &data, const std::string &mappingValue) {
    double incrementingValue = std::stod(mappingValue);

    std::stringstream ss;
    for (double & i : data) {
        i += incrementingValue;
        ss << " " << i;
    }
    return ss.str();
}

std::string MapTag::multiply(std::vector<double> &data, const std::string &mappingValue) {
    double mapValue = std::stod(mappingValue);
    std::stringstream ss;

    for (double &i : data) {
        i *= mapValue;
        ss << " " << i;
    }
    return ss.str();
}

void MapTag::printMapTag() const {
    std::cout << "Open  tag = " << openTag << "\n";
    std::cout << "Close tag = " << closeTag << "\n";
    std::cout << "Value     = " << mappingValue << "\n";
}
