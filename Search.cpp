#include <iostream>
#include <string>
#include "LogView.h"
#include <pcrecpp.h>
#include <vector>
#include <sstream>

std::string rawData(std::vector<Entry> entries) {
    std::ostringstream stream;
    for (auto iter : entries) {
        stream << iter.ID << ", " << iter.devName << ", " << iter.PSID << ", "
                << iter.entryType << ", " << iter.entryTime << ", "
                << iter.termStatus << ", "
 //               << iter.exitStatus << ", "
                << iter.hostName << "\n";
    }
    return stream.str();
}

auto search(std::string searchString, std::vector<Entry> entries) {
    pcrecpp::RE regex(R"!(^.+)()()!");
    auto test;
    return test;
}
