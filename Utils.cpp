/*
 * Utils.cpp
 *
 *  Created on: Dec 16, 2014
 *      Author: explicitness
 */
#include <iostream>
#include <ctime>
#include "LogView.h"
#include <sstream>

std::string epochConvert(long int unconvertedTime) {
    time_t newTime = unconvertedTime;
    struct tm convertedTime;
    time(&newTime);
    convertedTime = *gmtime(&newTime);
    std::ostringstream timeString;
    timeString << convertedTime.tm_hour << ":" << convertedTime.tm_min << ":"
            << convertedTime.tm_sec << " " << convertedTime.tm_year << "/"
            << convertedTime.tm_mon << "/" << convertedTime.tm_mday;
    return timeString.str();
}
