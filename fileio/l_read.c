#include <stdio.h>
#include <unistd.h>
#include "../lib/error_functions.h"

int main(void)
{
#define MAX_READ 20
    ssize_t readNum;
    ssize_t writeNum;
    char buffer[MAX_READ + 1];

    readNum = read(STDIN_FILENO, buffer, MAX_READ);
    if (readNum == -1) {
        errExit("read error");
    }

    buffer[MAX_READ] = '\0';
    //printf("%s\n", buffer);
    
    writeNum = write(STDOUT_FILENO, buffer, readNum);
    if (writeNum == -1) {
        errExit("write error");
    }
    
    
    return 0;
}
