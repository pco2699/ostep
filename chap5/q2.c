#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    close(STDOUT_FILENO);
    int fd = open("./q2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("I am child");
        printf("I am child");
        printf("I am child");
    } else {
        printf("I am parent");
        printf("I am parent");
        printf("I am parent");
    }

    return 0;
}