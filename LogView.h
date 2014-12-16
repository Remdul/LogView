#ifndef LOGVIEW_H_
#define LOGVIEW_H_

#include <iostream>
#include <string>
#include <vector>
#include <utmp.h>
#include <ctime>


void menuOutput(std::vector<utmp> blockVector);
std::string epochConvert(long int unconvertedTime);
std::string rawData(std::vector<utmp> blockEntries);

#endif /* LOGVIEW_H_ */
