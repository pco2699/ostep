#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pipefd[2];
    char buf[256];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {  
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("hello,Iamchild(pid:%d)\n", (int) getpid());
    } else {
        int rc2 = fork();
        if (rc2 < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (rc2 == 0) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            scanf("%s", buf);
            printf("%s", buf);
            printf("hello, I am child2 (pid:%d)\n", (int) getpid());
        }
    }
    return 0;
}