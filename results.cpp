#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <utmp.h>
#include "LogView.h"
#include <fstream>

void saveToFile(std::vector<utmp> blockEntries, std::string fileName)

{
	//Writes to fileName in the working directory with each iteration of the for loop.
	std::ofstream a_file ( fileName );
	for (auto iter : blockEntries)
	{
		a_file << iter;
		a_file.close();
	}

}

void resultsHeader()
{
	//LINE 1
	std::cout << std::setw(10) << "User" << std::setw(6) << "" << std::setw(8)
			<< "Device" << std::setw(8) << "" << std::setw(8) << "Entry"
			<< std::setw(15) << "Entry" << std::setw(8) << "Exit"
			<< std::setw(20) << "" << std::endl;
	//LINE 2
	std::cout << std::setw(10) << "Name" << std::setw(6) << "ID" << std::setw(8)
			<< "Name" << std::setw(8) << "PSID" << std::setw(8) << "Type"
			<< std::setw(15) << "Time" << std::setw(8) << "Status"
			<< std::setw(20) << "Host Name" << "\n" << std::endl;
}

void resultsBody(utmp blockInput)
{
	std::cout << std::setw(10) << blockInput.ut_user << std::setw(6)
			<< blockInput.ut_id << std::setw(8) << blockInput.ut_line
			<< std::setw(8) << blockInput.ut_pid << std::setw(8)
			<< blockInput.ut_type << std::setw(15) << blockInput.ut_tv.tv_sec
			<< std::setw(8) << blockInput.ut_exit.e_exit << std::setw(20)
			<< blockInput.ut_host << std::endl;
}

void resultsOutput(std::vector<utmp> blockVector)
{
	resultsHeader();

	for (auto iter : blockVector)
	{
		resultsBody(iter);

	}

}
