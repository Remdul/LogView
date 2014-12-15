// First Commit

#include <iostream>
#include <fstream>

using namespace std;

int main()

{
	ifstream wtmp("/var/log/wtmp", ios::binary | ios::in);
	ifstream utmp;


    char * x;
    wtmp.open("silly.dat", ios::binary | ios::in);
    wtmp.read(x, 4082);
    std::cout << x << std::endl;
	return 0;

}
