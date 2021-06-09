//
// Created by alexa on 03/12/2020.
//

#include <sstream>
#include "TagFactory.h"
#include "SortTag.h"

std::string TagFactory::extractTagType(const std::string &openTag) {
    std::string tagType;
    // Start i from 1 to avoid '<' element
    for (int i = 1; openTag[i] != '-'; i++) {
        tagType.push_back(openTag[i]);
    }
    return tagType;
}

std::string TagFactory::setTagOperation(const std::string &openTag) {
    std::string tagOperation;
    // Start i from 5 avoiding the '-' element
    for (int i = 5; i != 7; i++) {
        tagOperation.push_back(openTag[i]);
    }
    return tagOperation;
}

IMLAttributes::AggregateOperations TagFactory::extractAggType(const std::string &openTag) {
    return getAggType(setTagOperation(openTag));
}

IMLAttributes::MappingOperations TagFactory::extractMapType(const std::string &openTag) {
    return getMapType(setTagOperation(openTag));
}

IMLAttributes::SortingOperations TagFactory::extractSortType(const std::string &openTag) {
    return getSortType(setTagOperation(openTag));
}

IMLAttributes::AggregateOperations TagFactory::getAggType(const std::string &type) {
    char c = type[0];

    switch (c) {
        case 'S':
            return IMLAttributes::AggregateOperations::SUM;
        case 'P':
            return IMLAttributes::AggregateOperations::PRO;
        case 'A':
            return IMLAttributes::AggregateOperations::AVG;
        case 'F':
            return IMLAttributes::AggregateOperations::FST;
        case 'L':
            return IMLAttributes::AggregateOperations::LST;
        default:
            exit(1);
    }
}

IMLAttributes::MappingOperations TagFactory::getMapType(const std::string &type) {
    char c = type[0];
    switch (c) {
        case 'I':
            return IMLAttributes::MappingOperations::INC;
        case 'M':
            return IMLAttributes::MappingOperations::MLT;
        default:
            exit(1);
    }
}

IMLAttributes::SortingOperations TagFactory::getSortType(const std::string &type) {
    char c = type[0];
    switch (c) {
        case 'R':
            return IMLAttributes::SortingOperations::REV;
        case 'O':
            return IMLAttributes::SortingOperations::ORD;
        case 'S':
            return IMLAttributes::SortingOperations::SLC;
        case 'D':
            return IMLAttributes::SortingOperations::DST;
        default:
            exit(1);
    }
}

std::string TagFactory::calculateTags(const std::string &openTag, const std::string &closeTag, std::vector<double> &data,
                                      const std::string &attribute) {

    std::stringstream os;

    if (extractTagType(openTag) == "AGG") {
        if (extractAggType(openTag) == IMLAttributes::AggregateOperations::SUM) {
            os << " " << AggregateTag::sums(data);
            return os.str();
        } else if (extractAggType(openTag) == IMLAttributes::AggregateOperations::PRO) {
            os << " " << AggregateTag::pros(data);
            return os.str();
        } else if (extractAggType(openTag) == IMLAttributes::AggregateOperations::AVG) {
            os << " " << AggregateTag::average(data);
            return os.str();
        } else if (extractAggType(openTag) == IMLAttributes::AggregateOperations::FST) {
            os << " " << AggregateTag::firstElement(data);
            return os.str();
        } else if (extractAggType(openTag) == IMLAttributes::AggregateOperations::LST) {
            os << " " << AggregateTag::lastElement(data);
            return os.str();
        }
    } else if (extractTagType(openTag) == "SRT") {
        if (extractSortType(openTag) == IMLAttributes::SortingOperations::REV) {
            return SortTag::reverses(data);
        } else if (extractSortType(openTag) == IMLAttributes::SortingOperations::ORD) {
            return SortTag::ordereds(data, attribute);
        } else if (extractSortType(openTag) == IMLAttributes::SortingOperations::SLC) {
            return SortTag::sublists(data, attribute);
        } else {
            return SortTag::distincts(data);
        }
    } else if (extractTagType(openTag) == "MAP") {
        if (extractMapType(openTag) == IMLAttributes::MappingOperations::INC) {
            os << MapTag::increment(data, attribute) << " ";
            return os.str();
        } else {
            os << MapTag::multiply(data, attribute) << " ";
            return os.str();
        }
    }
    return "Invalid tag data";
}