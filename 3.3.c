#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <gnu/libc-version.h>

int main(void)
{
    char *libc_version;
    size_t n;
    n = confstr(_CS_GNU_LIBC_VERSION , NULL, (size_t)0);
    
    libc_version = malloc(n);
    if (libc_version == NULL) {
        printf("malloc error!");
        return 0;
    }
    confstr(_CS_GNU_LIBC_VERSION, libc_version, n);
    printf("libc all version = %s\n", libc_version);

    free(libc_version);

    printf("libc version = %s\n", gnu_get_libc_version());
    printf("libc release = %s\n", gnu_get_libc_release());

    return 0;
}




