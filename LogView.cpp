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
        file.seekg(0, file.beg);
        utmp blockEntry;
        // read data as a block:
        file.read((char *) &blockEntry, sizeof(utmp));
        std::cout << "Reading " << sizeof(utmp) << " characters... " << std::endl;
        std::cout << blockEntry.ut_type << std::endl;
        std::cout << blockEntry.ut_user << std::endl;
        std::cout << blockEntry.ut_pid << std::endl;

        if (file)
            std::cout << "all characters read successfully." << std::endl;
        else
            std::cout << "error: only " << file.gcount() << " could be read"
                    << std::endl;
        file.close();
    }
    return 0;
}




/*
 *     short   ut_type;               Type of record
       pid_t   ut_pid;                PID of login process
       char    ut_line[UT_LINESIZE];  Device name of tty - "/dev/"
       char    ut_id[4];              Terminal name suffix,
                                        or inittab(5) ID
       char    ut_user[UT_NAMESIZE];  Username
       char    ut_host[UT_HOSTSIZE];  Hostname for remote login, or
                                        kernel version for run-level
                                        messages
       struct  exit_status ut_exit;   Exit status of a process
                                        marked as DEAD_PROCESS; not
                                        used by Linux init(8)
        The ut_session and ut_tv fields must be the same size when
          compiled 32- and 64-bit.  This allows data files and shared
          memory to be shared between 32- and 64-bit applications.
   #if __WORDSIZE == 64 && defined __WORDSIZE_COMPAT32
       int32_t ut_session;            Session ID (getsid(2)),
                                        used for windowing
       struct {
           int32_t tv_sec;            Seconds
           int32_t tv_usec;           Microseconds
       } ut_tv;                       Time entry was made
   #else
        long   ut_session;            Session ID
        struct timeval ut_tv;         Time entry was made
   #endif

       int32_t ut_addr_v6[4];         Internet address of remote
                                        host; IPv4 address uses
                                        just ut_addr_v6[0]
       char __unused[20];             Reserved for future use
 *
 * */
