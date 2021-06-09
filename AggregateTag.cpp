//
// Created by alexa on 02/12/2020.
//

#include "AggregateTag.h"

//template<class T>
AggregateTag::AggregateTag(const std::string &openTag, const std::string &closeTag, std::string &data) {
    setOpenTag(openTag);
    setCloseTag(closeTag);
    setOperation(operation);
    setData(data);
}

//template<class T>
const std::string &AggregateTag::getOpenTag() const {
    return openTag;
}

//template<class T>
void AggregateTag::setOpenTag(const std::string &openTag) {
    if (openTag.empty()) {
        std::cout << "Empty opening tag.";
        return;
    } else {
        this->openTag = openTag;
    }
}

//template<class T>
const std::string &AggregateTag::getCloseTag() const {
    return closeTag;
}

//template<class T>
void AggregateTag::setCloseTag(const std::string &closeTag) {
    if (closeTag.empty()) {
        std::cout << "Empty closing tag.";
        return;
    } else {
        this->closeTag = closeTag;
    }
}

//template<class T>
const IMLAttributes::AggregateOperations &AggregateTag::getOperation() const {
    return operation;
}

//template<class T>
void AggregateTag::setOperation(const IMLAttributes::AggregateOperations &operation) {
    this->operation = operation;
}

//template<class T>
const std::string &AggregateTag::getData() const {
    return data;
}

//template<class T>
void AggregateTag::setData(const std::string &data) {
    for (const auto &i : data) {
        this->data.push_back(i);
    }
}

double AggregateTag::sums(const std::vector<double>& data) {
    double result = 0;
    for (const auto &it : data) {
        result += it;
    }
    return result;
}

double AggregateTag::pros(const std::vector<double>& data) {
    double result = 1;
    for (const auto &it : data) {
        result *= it;
    }
    return result;
}

double AggregateTag::average(const std::vector<double>& data) {
    return (sums(data) / data.size());
}

double AggregateTag::firstElement(std::vector<double> data) {
    return data[0];
}

double AggregateTag::lastElement(std::vector<double> data) {
    return data[data.size() - 1];
}

//template<class T>
void AggregateTag::printAggregateTag() const {
    std::cout << "Open  tag = " << openTag << "\n";
    std::cout << "Close tag = " << closeTag << "\n";
}