#ifndef LOGVIEW_H_
#define LOGVIEW_H_

#include <iostream>
#include <string>
#include <utmp.h>

class Entry
{
public:
    Entry(){}
    void setEntry(char newUserName, char newID, char newDevName, pid_t newPSID, short newEntryType, int32_t newEntryTime, long newTermStatus, struct newExitStatus, char newHostName);
    void printEntry();
private:
		char userName;
		char ID;
		char devName;
		pid_t PSID;
		short entryType;
		int32_t entryTime;
		long termStatus;
		struct exitStatus;
		char hostName;
};

void menuHeader();
void menuBody();
void menuFooter();

#endif /* LOGVIEW_H_ */
