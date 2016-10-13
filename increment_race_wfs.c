#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static long long int ITERS = 100000000;
long long int c1;
long long int c2;


void *mythread(void *dummy) {
    int i;
    for (i = 0; i < ITERS; i++) {
        c1++;
    }
    return NULL;
}

int main() {
    pthread_t thid;
    int result = pthread_create(&thid, (pthread_attr_t *) NULL, mythread, NULL);
    if (result != 0) {
        printf("Error on thread create, return value = %d\n", result);
        exit(1);
    }
    printf("Thread created, thid %lu\n", thid);
    int i;
    for (i = 0; i < ITERS; i++) {
        c2++;
    }
    pthread_join(thid, (void **) NULL);
    printf("%lli should be %lli\n", c1 + c2, ITERS * 2);
    return 0;
}
