//
// Created by alexa on 08/12/2020.
//

#ifndef IML_SORTTAG_H
#define IML_SORTTAG_H

#include "IMLAttributes.h"
#include "TagFactory.h"

class SortTag {
public:
    SortTag(const std::string &openTag, const std::string &closeTag, const std::string &data, const std::string &value);

    const std::string &getOpenTag() const;
    void setOpenTag(const std::string &openTag);

    const std::string &getCloseTag() const;
    void setCloseTag(const std::string &closeTag);

    const std::string &getData() const;
    void setData(const std::string &data);

    const std::string &getValue() const;
    void setValue(const std::string &value);

    IMLAttributes::SortingOperations getAttribute() const;
    void setAttribute(IMLAttributes::SortingOperations attribute);

    static std::string reverses(std::vector<double> &data);
    static std::string ordereds(std::vector<double> &data, const std::string &attribute);
    static std::string distincts(std::vector<double> &data);
    static std::string sublists(std::vector<double> &data, const std::string &attribute);

    static void removeDuplicates(std::vector<double>& data);

private:
    std::string openTag;
    std::string closeTag;
    std::string data;
    std::string attributeValue;
    IMLAttributes::SortingOperations attribute;
};


#endif //IML_SORTTAG_H
