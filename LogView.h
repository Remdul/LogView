#ifndef LOGVIEW_H_
#define LOGVIEW_H_

#include <iostream>
#include <string>

class Entries
{
public:
    Entries(){}
    void setEntries(std::string newUserName, std::string newID, std::string newDevName, int newPSID, std::string newEntryType, std::string newEntryTime, std::string newTermStatus, std::string newExitStatus, std::string newHostName);
    void printEntries();
private:
		std::string userName;
		std::string ID;
		std::string devName;
		int PSID;
		std::string entryType;
		std::string entryTime;
		std::string termStatus;
		std::string exitStatus;
		std::string hostName;
};

void menuHeader();
void menuBody();
void menuFooter();

#endif /* LOGVIEW_H_ */
