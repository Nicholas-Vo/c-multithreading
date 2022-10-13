#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*     Errors with pthread_create():
       EAGAIN - Insufficient resources to create another thread.
       EAGAIN - A system-imposed limit on the number of threads was encountered
       EINVAL - Invalid settings in attr
       EPERM  - No permission to set the scheduling policy and parameters specified in attr */

struct Info {
    char name[20];
    int age;
};

void *doStuff(void *data) {
    struct Info *info = (struct Info*) data;

    for (int i = 0; i < 5; i++) {
        printf("Name: %s Age: %d\n", info->name, info->age);
    }
    return NULL;
}

int main() {
    pthread_t id; // int used to define the thread in the system
    struct Info *info = malloc(sizeof(info));

    strcpy(info->name, "Nicholas");
    info->age = 26;

    pthread_create(&id, NULL, doStuff, (void *) info);
    pthread_join(id, NULL); // Blocks the calling thread until threadID terminates
    pthread_exit(NULL);
    return 0;
}
