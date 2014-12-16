#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <stdio.h>
#include <ctype.h>
#include <utmp.h>
#include <vector>
#include "LogView.h"

void menuSelection(std::string x)
{
	switch (x)
	{
	case 'Search':
		std::cout << "Search For Stuff!" << std::endl;
		break;
	case 'Exit Program':
		std::cout << "Exit Program Stuff!" << std::endl;
		break;
	case 'Print Menu':
		std::cout << "Print Menu Stuff!" << std::endl;
		break;
	case 'Export':
		std::cout << "Export Stuff!" << std::endl;
		break;
	default:
		std::cout << "Blargh!" << std::endl;
	}
}

int main()
{
	std::ifstream utmpFile("/var/run/utmp", std::ifstream::binary);
	std::ifstream wtmpFile("/var/log/wtmp", std::ifstream::binary);
	std::vector<utmp> blockEntries;
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
			std::cout << "Reading " << sizeof(utmp) << " characters... "
					<< std::endl;
			blockEntries.push_back(blockEntry);
		}

		std::cout << "Read in " << blockEntries.size() << " blocks."
				<< std::endl;
		std::cout << rawData(blockEntries) << std::endl;

		utmpFile.close();
	}
	return 0;
}
