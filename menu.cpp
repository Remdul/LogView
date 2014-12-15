#include <iostream>
#include <iomanip>
#include <string>

void menuHeader()
{
	std::cout << std::setw(12) << "User Name" << std::setw(6) << "ID" << std:: setw(12) << "Dev Name" << std::setw(6) << "PSID" << std::setw(12) << "Entry Type" << std::setw(14) << "Entry Time" << std::setw(14) << "Termination" << std::setw(14) << "Exit Status" << std::setw(12) << "Host Name" << std::endl;
}


void menuBody(std::string name, int num)
{
	std::cout << std::setw(12) << blockInput.ut_user << std::setw(6) << blockInput.ut_id << std:: setw(12) << blockInput.ut_line << std::setw(6) << blockInput.ut_pid << std::setw(12) << blockInput.ut_type << std::setw(14) << blockInput.ut_tv << std::setw(14) << blockInput.ut_status << std::setw(14) << blockInput.ut_exit << std::setw(12) << ut_host << std::endl;
}
