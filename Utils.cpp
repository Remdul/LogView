/*
 * Utils.cpp
 *
 *  Created on: Dec 16, 2014
 *      Author: explicitness
 */
#include <iostream>
#include <ctime>

int epochConvert (x)
{
  time_t epochTime;
  struct tm * ptm;

  time ( &epochTime );

  ptm = gmtime ( &epochTime );

  std::cout << "Current time around the World:" << std::endl;

  return 0;
}



