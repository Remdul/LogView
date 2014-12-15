#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <stdio.h>
#include <ctype.h>

int main() {

    std::ifstream file("/var/log/wtmp", std::ifstream::binary);
    if (file) {
        // get length of file:
        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);

        char * buffer = new char[length];

        std::cout << "Reading " << length << " characters... " << std::endl;
        // read data as a block:
        file.read(buffer, length);

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
