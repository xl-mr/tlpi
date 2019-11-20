#include <stdio.h>
#include <unistd.h>

int
main(void)
{
    printf("ppid = %d\n", getppid());
    printf("pid = %d\n", getpid());

    sleep(10);

    return 0;
}
