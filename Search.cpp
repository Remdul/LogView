#include <iostream>
#include <string>
#include "LogView.h"
#include <pcrecpp.h>
#include <vector>
#include <sstream>

std::string hexToAscii(std::string hex) {
    int len = hex.length();
    std::string newString;
    for (int i = 0; i < len; i += 2) {
        string byte = hex.substr(i, 2);
        char chr = (char) (int) strtol(byte.c_str(), NULL, 16);
        newString.push_back(chr);
    }
    return newString;
}

std::string rawData(std::vector<utmp> blockEntries) {
    std::ostringstream stream;
    for (auto iter : blockEntries) {
        stream << iter.ut_user << ", " << iter.ut_pid << ", " << iter.ut_host
                << ", " << iter.ut_session << ", " << iter.ut_addr_v6 << ", "
                << iter.ut_id << ", " << iter.ut_line << ", "
                << iter.ut_exit.e_exit << ", " << iter.ut_exit.e_termination
                << ", " << epochConvert((long int)iter.ut_tv.tv_sec) << "\n";
    }
    return stream.str();
}
/*
 * reboot, 0, 3.13.0-40-generic, 0, 0x7fff5bcc427c, ~~, ~, 0, 0, 1418589862
 * bryan, 4863, :0, 0, 0x7fff5bcc427c, /3, pts/3, 0, 0, 1418652552
 */
std::string searchString(std::string searchString, std::vector<utmp> entries) {
    std::string findGroup = "test";
    pcrecpp::RE regex(searchString);
    if (!regex.PartialMatch(rawData(entries))) {
        std::cout << "Could not parse data with search string: " << searchString << std::endl;
        throw string("Error");
    }
    return findGroup;
}
