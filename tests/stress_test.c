#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 8
#define ITER 10000

void *worker(void *arg) {
    for (int i=0;i<ITER;i++) {
        system("echo x >/dev/null");
    }
    return NULL;
}

int main() {
    pthread_t th[THREADS];
    for (int i=0;i<THREADS;i++) pthread_create(&th[i], NULL, worker, NULL);
    for (int i=0;i<THREADS;i++) pthread_join(th[i], NULL);
    printf("Stress test OK\n");
    return 0;
}
