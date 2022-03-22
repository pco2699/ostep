#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        int rc_wait2 = wait(NULL); // 子供でwaitするとエラーになる
        printf("hello, I am child (pid:%d)(rc_wait:%d)\n", (int) getpid(), rc_wait2);

    } else {
        int rc_wait= wait(NULL); // 親のpidが入る
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",
                rc, rc_wait, (int) getpid());                
    }

    return 0;
}