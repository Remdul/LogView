#ifndef LOGVIEW_H_
#define LOGVIEW_H_

#include <iostream>
#include <string>
#include <utmp.h>

class Entry {
public:
    Entry() {}
    void setEntry(char newUserName, char newID, char newDevName, pid_t newPSID,
            short int newEntryType, int32_t newEntryTime,             char newHostName);
    void printEntry();
private:
    char userName;
    char ID;
    char devName;
    pid_t PSID;
    short int entryType;
    int32_t entryTime;
    char hostName;
};

void menuHeader();
void menuBody();

#endif /* LOGVIEW_H_ */
