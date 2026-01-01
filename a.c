#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
int
main(void)
{
    struct rlimit new, old;

    /* to trigger crash for GMP builds with alloca() enabled */
    if (getrlimit(RLIMIT_STACK, &old)) {
        perror("getrlimit");
        return 1;
    }
    printf("old limits: %llu %llu\n", old.rlim_cur, old.rlim_max);
    new.rlim_max = old.rlim_max;
    new.rlim_cur = 128*1000;
    if (setrlimit(RLIMIT_STACK, &new)) {
        perror("setrlimit");
        return 1;
    }
    if (getrlimit(RLIMIT_STACK, &old)) {
        perror("getrlimit");
        return 1;
    }
    printf("new limits: %llu %llu\n", old.rlim_cur, old.rlim_max);
    return 0;
}
