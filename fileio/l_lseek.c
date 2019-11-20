#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    ssize_t readNum;
    off_t file_pos;
    char buf[100] = {'\0'};

    fd = open("1.txt", O_RDWR);

    if (fd == -1) {
        fprintf(stderr, "1.txt open file error");
        exit(EXIT_FAILURE);
    }

    file_pos = lseek(fd, 30, SEEK_CUR);

    readNum = read(fd, buf, 5);
    if (readNum == -1) {
        fprintf(stderr, "read file error");
        exit(EXIT_FAILURE);
    }
    buf[5] = '\0';

    printf("read num = %ld\n", readNum);

    printf("file content = %s\n", buf);

    printf("file cur pos = %ld\n", file_pos);

    close(fd);

    return 0;
}
