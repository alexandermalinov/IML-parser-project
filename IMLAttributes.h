//
// Created by alexa on 02/12/2020.
//

#ifndef IML_IMLATTRIBUTES_H
#define IML_IMLATTRIBUTES_H

class IMLAttributes {
public:
    enum class AggregateOperations {
        SUM, PRO, AVG, FST, LST
    };

    enum class MappingOperations {
        INC, MLT
    };

    enum class SortingOperations {
        REV, ORD, SLC, DST
    };
};


#endif //IML_IMLATTRIBUTES_H
