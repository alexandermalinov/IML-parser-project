#include <iostream>
#include <regex>

#include "IMLAttributes.h"

#include "AggregateTag.h"
#include "AggregateTag.cpp"

#include "MapTag.h"
#include "MapTag.cpp"

#include "TagFactory.h"
#include "TagFactory.cpp"

#include "IMLParser.h"
#include "IMLParser.cpp"

#include "SortTag.h"
#include "SortTag.cpp"

#include "TagValidation.h"
#include "TagValidation.cpp"

const std::string FILES_PATH = "/home/alexander/University/data-structures/IML-parser-project/testing-files/";

int main() {

    try {
        IMLParser imlParser1(FILES_PATH + "test1.txt", "test11.txt");
    } catch (const char* msg) {
        std::cerr << msg << "\n";
    }

    return 0;
}
