#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    unsigned char ch;

/*  '0' = 0x30 = %00110000
    '1' = 0x31 = %00110001   */

    ofstream ostream("test.txt", ios::binary);
    ostream.write("1", 1);
    ostream.close();

    ifstream istream("/var/log/wtmp");
    while (ch = istream.get() != NULL) {
        printf("%d", (ch & 0x80) / 0x80);
        printf("%d", (ch & 0x40) / 0x40);
        printf("%d", (ch & 0x20) / 0x20);
        printf("%d", (ch & 0x10) / 0x10);
        printf("%d", (ch & 0x08) / 0x08);
        printf("%d", (ch & 0x04) / 0x04);
        printf("%d", (ch & 0x02) / 0x02);
        printf("%d\n", (ch & 0x01) / 0x01);
        //Output: 00110001
    }
    istream.close();

    cin.ignore();
    return 0;
}
