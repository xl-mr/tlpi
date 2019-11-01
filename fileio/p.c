#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    dprintf(STDOUT_FILENO, "%s\n", "test stdout-fileno hello world!");

    char *str = "hello world!";
    printf("%s\n", str);
    fprintf(stderr, "stderr: %s\n", str);

    int inputFd = open("2.txt", O_RDWR);
    if (inputFd == -1) {
        fprintf(stderr, "error: %s\n", strerror(errno));
    }
    int num = dprintf(inputFd, "%s\n", str);
    if (num < 0) {
        fprintf(stderr, "error: %s\n", strerror(errno));
    }
    close(inputFd);

    //sprintf
    char formateStr[100];
    sprintf(formateStr, "%s format str", str);
    printf("%s\n", formateStr);

    //snprintf
    char snStr[10];
    snprintf(snStr, 10, "%s", str);
    printf("%s\n", snStr);


    printf("EPERM errno = %d\n", EPERM);

    return 0;
}
