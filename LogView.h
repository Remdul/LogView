#ifndef LOGVIEW_H_
#define LOGVIEW_H_

#include <iostream>
#include <string>
#include <vector>
#include <utmp.h>

<<<<<<< HEAD
class Entry {
public:
    Entry() {}
    void setEntry(char newUserName, char newID, char newDevName, pid_t newPSID,
            short newEntryType, int32_t newEntryTime,             char newHostName);
    void printEntry();
private:
    char userName;
    char ID;
    char devName;
    pid_t PSID;
    short entryType;
    int32_t entryTime;
    char hostName;
=======
class
{

public:

private:

>>>>>>> e2be7d77afb102e2605b2b1d148fb1d6bfef322d
};

void menuOutput(std::vector blockVector);

#endif /* LOGVIEW_H_ */
