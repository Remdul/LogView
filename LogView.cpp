#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <stdio.h>
#include <ctype.h>
#include <utmp.h>

void Entry::setEntry(char newUserName, char newID, char newDevName,
        pid_t newPSID, short int newEntryType, int32_t newEntryTime,
        char newHostName) {
    newUserName = userName;
    newID = ID;
    newDevName = devName;
    newPSID = PSID;
    newEntryType = entryType;
    newEntryTime = entryTime;
    newHostName = hostName;

}

int main() {

    std::ifstream file("/var/run/utmp", std::ifstream::binary);
    if (file) {
        // get length of file:
        file.seekg(0, file.end);
        file.seekg(0, file.beg);
        utmp blockEntry;
        // read data as a block:
        file.read((char *) &blockEntry, sizeof(utmp));
        std::cout << "Reading " << sizeof(utmp) << " characters... "
                << std::endl;
        Entry newEntry;
        newEntry.setEntry(blockEntry.ut_user, blockEntry.ut_id,
                blockEntry.ut_line, blockEntry.ut_pid, blockEntry.ut_type,
                blockEntry.ut_tv, blockEntry.ut_host);

        blockEntry.ut_user
        if (file)
            std::cout << "all characters read successfully." << std::endl;
        else
            std::cout << "error: only " << file.gcount() << " could be read"
                    << std::endl;
        file.close();
    }
    return 0;
}
