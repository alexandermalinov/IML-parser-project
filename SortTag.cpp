//
// Created by alexa on 08/12/2020.
//

#include <iterator>
#include <set>
#include <unordered_set>
#include "SortTag.h"

SortTag::SortTag(const std::string &openTag, const std::string &closeTag, const std::string &data,
                 const std::string &value) {
    setOpenTag(openTag);
    setCloseTag(closeTag);
    setData(data);
    setValue(value);
}

const std::string &SortTag::getOpenTag() const {
    return openTag;
}

void SortTag::setOpenTag(const std::string &openTag) {
    if (openTag.empty()) {
        std::cout << "Empty opening tag.\n";
        return;
    }
    this->openTag = openTag;
}

const std::string &SortTag::getCloseTag() const {
    return closeTag;
}

void SortTag::setCloseTag(const std::string &closeTag) {
    if (closeTag.empty()) {
        std::cout << "Empty closing tag.\n";
        return;
    }
    this->closeTag = closeTag;
}

const std::string &SortTag::getData() const {
    return data;
}

void SortTag::setData(const std::string &data) {
    if (data.empty()) {
        std::cout << "Empty data.\n";
        return;
    }
    this->data = data;
}

const std::string &SortTag::getValue() const {
    return attributeValue;
}

void SortTag::setValue(const std::string &value) {
    if (value.empty()) {
        std::cout << "Empty mappingValue.\n";
        return;
    }
    this->attributeValue = value;
}

IMLAttributes::SortingOperations SortTag::getAttribute() const {
    return attribute;
}

void SortTag::setAttribute(IMLAttributes::SortingOperations attribute) {
    SortTag::attribute = attribute;
}

std::string SortTag::reverses(std::vector<double> &data) {
    std::reverse(data.begin(), data.end());
    std::stringstream ss;
    for (const auto &it : data)
        ss << " " << it << " ";
    return ss.str();
}

std::string SortTag::ordereds(std::vector<double> &data, const std::string &attribute) {
    if (attribute == "ASC") {
        std::sort(data.begin(), data.end());
    } else if (attribute == "DSC") {
        std::sort(data.begin(), data.end(), std::greater<>());
    } else {
        return "Invalid attribute!";
    }

    std::stringstream ss;
    for (const auto &it : data) {
        ss << " " << it << " ";
    }
    return ss.str();
}

std::string SortTag::distincts(std::vector<double> &data) {
    removeDuplicates(data);
    std::stringstream ss;
    for (const auto &i : data) {
        ss << " " << i << " ";
    }
    return ss.str();
}

std::string SortTag::sublists(std::vector<double> &data, const std::string &attribute) {
    int index = std::stoi(attribute);

    auto first = data.begin() + index;
    auto last = data.end();
    std::vector<int> subVector(first, last);

    std::stringstream ss;
    for (const auto &it : subVector) {
        ss << " " << it << " ";
    }
    return ss.str();
}

void SortTag::removeDuplicates(std::vector<double> &data) {
    std::set<double> dataSet;
    std::vector<double> resultData;
    // 1 75 2 1
    for(double x : data) {
        if (dataSet.find(x) == dataSet.end()) {
            dataSet.insert(x);
            resultData.push_back(x);
        }
    }
    std::swap(data, resultData);
}
