#include <unistd.h>
#include <sys/reboot.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
    
    sync();
    if (reboot(RB_AUTOBOOT) == -1) {
        printf("%s\n", strerror(errno));
    }

    return 0;
}
