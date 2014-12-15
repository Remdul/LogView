#include <iostream>
#include <iomanip>
#include <string>
#include "LogView.h"

void menuHeader() {
    std::cout << std::setw(12) << "User Name" << std::setw(6) << "ID"
            << std::setw(12) << "Dev Name" << std::setw(6) << "PSID"
            << std::setw(12) << "Entry Type" << std::setw(14) << "Entry Time"
            << std::setw(14) << "Termination" << std::setw(14) << "Exit Status"
            << std::setw(12) << "Host Name" << std::endl;
}

void menuBody(Entry blockInput) {
    std::cout << std::setw(12) << blockInput.userName << std::setw(6)
            << blockInput.ID << std::setw(12) << blockInput.devName
            << std::setw(6) << blockInput.PSID << std::setw(12)
            << blockInput.entryType << std::setw(14) << blockInput.entryTime
            << std::setw(14) << blockInput.termStatus << std::setw(14)
            << blockInput.exitStatus << std::setw(12) << blockInput.hostName << std::endl;
}
