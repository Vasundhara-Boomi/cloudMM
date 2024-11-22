#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 100

int main(){

    int p2c[2], c2p[2];
    pid_t pid;
    char msg[MAX_SIZE], reply[MAX_SIZE];

    if (pipe(p2c) == -1 || pipe(c2p) == -1 || (pid = fork()) < 0){
        perror("Error");
        return 1;
    }

    if pid{
        close(p2c[0]); close(c2p[1]);
        printf("Parent, ent");
        fgets(msg, MAXSIZE, stdin);
        write(p2c[1], msg, strlen(msg)+1);
        read(c2p[0], reply, MAXSIZE);
        printf("Parent received: %s\n", reply);
    } else{
        close(p2c[1]); close(c2p[0]);
        read(p2c[0], reply, MAXSIZE);
        printf("Child received %s", reply);
        printf();
        fgets(msg, MAXSIZE, stdin);
        write(c2p[1], msg, strlen(msg) + 1);
    }
    return 0;
}