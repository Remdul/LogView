#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <stdio.h>
#include <ctype.h>
#include <utmp.h>

int main() {

    std::ifstream file("/var/run/utmp", std::ifstream::binary);
    if (file) {
        // get length of file:
        file.seekg(0, file.end);
        int length = utmp;
        file.seekg(0, file.beg);

        utmp my_utmp;

        std::cout << "Reading " << length << " characters... " << std::endl;
        // read data as a block:
        file.read((char *) &my_utmp, sizeof(utmp)); //this will read 1 struct in
        //you will need to loop and repeat the process
        

        if (file)
            std::cout << "all characters read successfully." << std::endl;
        else
            std::cout << "error: only " << file.gcount() << " could be read"
                    << std::endl;
        file.close();
        for (int i = 0; i < length; i++) {
            if (!buffer[i] == NULL) {
                std::cout << buffer[i];
            }
        }
        delete[] buffer;
    }
    return 0;
}
