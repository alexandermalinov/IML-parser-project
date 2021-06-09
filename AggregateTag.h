//
// Created by alexa on 02/12/2020.
//

#ifndef IML_AGGREGATETAG_H
#define IML_AGGREGATETAG_H

#include <iostream>
#include <vector>
#include "TagFactory.h"

class AggregateTag {
public:
    AggregateTag(const std::string &openTag, const std::string &closeTag, std::string &data);

    const std::string &getOpenTag() const;
    void setOpenTag(const std::string &openTag);

    const std::string &getCloseTag() const;
    void setCloseTag(const std::string &closeTag);

    const IMLAttributes::AggregateOperations &getOperation() const;
    void setOperation(const IMLAttributes::AggregateOperations &operation);

    const std::string &getData() const;
    void setData(const std::string &data);

    static double sums(const std::vector<double>& data);
    static double pros(const std::vector<double>& data);
    static double average(const std::vector<double>& data);
    static double firstElement(std::vector<double> data);
    static double lastElement(std::vector<double> data);

    void printAggregateTag() const;

private:
    std::string openTag;
    std::string closeTag;
    std::string data;
    IMLAttributes::AggregateOperations operation;
};

#endif //IML_AGGREGATETAG_H
