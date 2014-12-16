#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <stdio.h>
#include <ctype.h>
#include <utmp.h>
#include <vector>
#include "LogView.h"
#include <iomanip>
#include <string>
#include <stdio.h>

int main(int argc, char *argv[])
{
    std::cout << argv[1] << " " << argv[2] << " " << argv[3] << std::endl;
    // Check for input command count. Only accepts 2-3 inputs. All others get menu.
    if (argc != 2 && argc != 3)
    {
        printf("Cofubar Inc. wtmp/utmp log viewing and searching tool. To use, please pass the following arguments:\n");
        printf("%25s : %30s\n", "Search <regex>", "Scan file for an entry.");
        printf("%25s : %30s\n", "Export <filename>", "Export to specified File.");
        printf("%25s : %30s\n\n", "View", "View contents of logs.");
        return 0;
    }

    // Initialize all variables needed
    std::ifstream utmpFile("/var/run/utmp", std::ifstream::binary);
    std::ifstream wtmpFile("/var/log/wtmp", std::ifstream::binary);
    std::vector<utmp> blockEntries;

    // Generate data from file.
    if (utmpFile)
    {
        // get length of file:
        utmpFile.seekg(0, utmpFile.end);
        utmpFile.seekg(0, utmpFile.beg);
        utmp blockEntry;

        // Read all blocks in:
        while (utmpFile)
        {
            utmpFile.read((char *) &blockEntry, sizeof(utmp));
            blockEntries.push_back(blockEntry);
        }
        utmpFile.close();
    }


    // Evaluate Commands
    if (argv[2] == "view" || "View")
    {
        std::cout << "I get here " << std::endl;
        resultsOutput(blockEntries);
        return 0;
    }
    if (argc == 3 && (argv[2] == "export" || argv[2] == "Export"))
    {
        std::cout << "Exporting File to: " << argv[3] << std::endl;
//        saveToFile(blockEntries, argv[3]);
        return 0;
    }
    else if (argc == 3 && (argv[2] == "search" || argv[2] == "Search"))
    {
        std::cout << "Searching for string: " << argv[3] << std::endl;
        searchString(argv[3], blockEntries);
        return 0;
    }
    else
    {
        std::cout << "Invalid Command." << std::endl;
        return 1;
    }
    return 0;
}
