#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <utmp.h>
#include "LogView.h"

void menuHeader() {
    std::cout << std::setw(15) << "User Name" << std::setw(10) << "ID"
            << std::setw(15) << "Device Name" << std::setw(10) << "PSID"
            << std::setw(15) << "Entry Type" << std::setw(15) << "Entry Time"
            << std::setw(15) << "Exit Status"
            << std::setw(15) << "Host Name" << std::endl;
}

void menuBody(utmp blockInput) {
    std::cout << std::setw(15) << blockInput.ut_user << std::setw(10)
            << blockInput.ut_id << std::setw(15) << blockInput.ut_line
            << std::setw(10) << blockInput.ut_pid << std::setw(15)
            << blockInput.ut_type << std::setw(15) << blockInput.ut_tv
            << std::setw(15) << blockInput.ut_exit << std::setw(15)
    		<< blockInput.ut_host << std::endl;
}

void menuOutput(std::vector blockVector) {
	menuHeader();

	for (auto iter : blockVector) {
		menuBody(iter);
	}
}
