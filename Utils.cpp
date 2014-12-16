#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "LogView.h"

// 1418589862 - Epoch test time 1
// 1418652552 - Epoch test time 2

std::string epochConvert(long int uncovertedTime) //< value not even used
{

    /*
     * THIS ONLY PULLS CURRENT TIME. ********************************************
     * Need to convert the Epoch time.
     */
    time_t newTime = uncovertedTime;
    struct tm convertedTime;
    time(&newTime);
    convertedTime = *gmtime(&newTime);
    //std::cout << convertedTime << std::endl; // <-- testing data

    //Formatted Return string declaration
    std::ostringstream timeString;

    //Formatting for: YYYY-MM-DD HH:MM:SS
    timeString << std::setfill('0') << std::setw(2)
            << convertedTime.tm_year + 1900 << "-" << std::setw(2)
            << convertedTime.tm_mon << "-" << std::setw(2)
            << convertedTime.tm_mday << " " << std::setw(2)
            << convertedTime.tm_hour << ":" << std::setw(2)
            << convertedTime.tm_min << ":" << std::setw(2)
            << convertedTime.tm_sec;

    return timeString.str();
}
