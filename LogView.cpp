#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <stdio.h>
#include <ctype.h>
#include <utmp.h>
#include <vector>
#include "LogView.h"
/*
 void menuSelection(int x)
 {
 switch (x)
 {
 case '1':
 std::cout << "Search For Stuff!" << std::endl;
 break;
 case '2':
 std::cout << "Export Stuff!" << std::endl;
 break;
 case '3':
 std::cout << "Result Stuff!" << std::endl;
 break;
 case '4':
 std::cout << "Exit Stuff!" << std::endl;
 break;
 default:
 std::cout << "Blargh!" << std::endl;
 }
 }
 */

int main()
{
	std::ifstream utmpFile("/var/run/utmp", std::ifstream::binary);
	std::ifstream wtmpFile("/var/log/wtmp", std::ifstream::binary);
	std::vector<utmp> blockEntries;
	std::string cont = "yes";

	while(cont == "yes" || cont == "Yes")
	{
		std::cout << "Please enter the appropriate number. " << std::endl << std::endl;
		std::cout << "[1] Search " << std::endl;
		std::cout << "[2] Export to file" << std::endl;
		std::cout << "[3] Results" << std::endl;

		if (utmpFile)
		{
			// get length of file:
			utmpFile.seekg(0, utmpFile.end);
			utmpFile.seekg(0, utmpFile.beg);
			utmp blockEntry;
			// read data as a block:
			while (utmpFile)
			{
				utmpFile.read((char *) &blockEntry, sizeof(utmp));
				// std::cout << "Reading " << sizeof(utmp) << " characters... "
				//		<< std::endl;
				blockEntries.push_back(blockEntry);
			}

			menuOutput(blockEntries);

			std::cout << "Read in " << blockEntries.size() << " blocks."
					<< std::endl;
			std::cout << rawData(blockEntries) << std::endl;

			utmpFile.close();
		}
	}
	return 0;
}
