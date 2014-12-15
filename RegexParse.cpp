#include <iostream>
#include <string>
#include <pcrecpp.h>
#include "LogView.h"

Entries parseFile(std::string line)
{
    std::string userName;
    std::string ID;
    std::string devName;
    int PSID;
    std::string entryType;
    std::string entryTime;
    std::string termStatus;
    std::string exitStatus;
    std::string hostName;

    pcrecpp::RE regex(R"!(^(.+?),(.+?),\s*([\d\.]+)(KM|M),\s*"(.+)")!");
    if (!regex.PartialMatch(line, &userName)) {
       // cout << "Could not parse ->" << line << "<-" << endl;
        throw string("Error");
    }

    Entries newEntry;
    newEntry.setEntries(userName, ID, devName, PSID, entryType, entryTime, termStatus, exitStatus, hostName);
    return newEntry;
}



