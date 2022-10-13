#include <pthread.h> // parts of pth_sum.c

double sum; // shared
int thread_count = 12;
int n = 25;

void *thread_sum(void *input);

int main(int argc, char *argv[]) {
    pthread_t *threads;

    for (int index = 0; index < thread_count; index++) {
        pthread_create(&threads[index], NULL, thread_sum, (void *) index);
    }
    for (int index = 0; index < thread_count; index++) {
        pthread_join(threads[index], NULL);
    }
}

void *thread_sum(void *input) {
    long my_rank = (long) input;
    long long i;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank + 1;
    long long my_last_i = my_first_i + my_n;

    for (i = my_first_i; i < my_last_i; i++) {
        sum = sum + i;
    }
    return NULL;
}