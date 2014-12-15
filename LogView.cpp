// First Commit

#include <iostream>
#include <fstream>

using namespace std;

int main()

{
	long int x;
	string line;
	ifstream wtmp("/var/log/wtmp", ios::binary | ios::in);
	ifstream utmp;


	while (getline(wtmp, line))
	{
		if (line != "")
		{
			cout << line << endl;
		}
	}






	return 0;

}
