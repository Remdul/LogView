#include <iostream>
#include <string>
#include "LogView.h"
#include <pcrecpp.h>
#include <vector>
#include <sstream>

std::string rawData(std::vector<utmp> blockEntries) {
    std::ostringstream stream;
    for (auto iter : blockEntries) {
        stream << iter.ut_user << ", "  << iter.ut_pid << ", " << iter.ut_host << "\n";
    }
    return stream.str();
}
/*
auto search(std::string searchString, std::vector<Entry> entries) {
    pcrecpp::RE regex(R"!(^.+)()()!");
    auto test;
    return test;
}*/
