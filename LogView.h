#ifndef LOGVIEW_H_
#define LOGVIEW_H_

#include <iostream>
#include <string>
#include <vector>
#include <utmp.h>

void menuOutput(std::vector<utmp> blockVector);
std::string rawData(std::vector<utmp> blockEntries);

#endif /* LOGVIEW_H_ */
