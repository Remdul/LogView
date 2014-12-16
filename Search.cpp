#include <iostream>
#include <string>
#include "LogView.h"
#include <pcrecpp.h>
#include <vector>
#include <sstream>

std::string hexToAscii(std::string hex)
{
    int len = hex.length();
    std::string newString;
    for(int i=0; i< len; i+=2)
    {
        string byte = hex.substr(i,2);
        char chr = (char) (int)strtol(byte.c_str(), NULL, 16);
        newString.push_back(chr);
    }
    return newString;
}

std::string rawData(std::vector<utmp> blockEntries) {
    std::ostringstream stream;
    for (auto iter : blockEntries) {
        stream << iter.ut_user << ", "  << iter.ut_pid << ", " << iter.ut_host << ", " << iter.ut_session << ", " << iter.ut_addr_v6 << ", " << iter.ut_id << ", " << iter.ut_line << ", " << iter.ut_exit.e_exit << ", " << iter.ut_exit.e_termination << ", " << iter.ut_tv.tv_sec << "\n";
    }
    return stream.str();
}
/*
auto search(std::string searchString, std::vector<Entry> entries) {
    pcrecpp::RE regex(R"!(^.+)()()!");
    auto test;
    return test;
}*/
