#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int ITERS = 100000000;
bool array[4];


void *mythread(void *dummy) {
    pthread_t mythid;
    mythid = pthread_self();
    int i;
    bool v = false;
    for (i = 0; i < ITERS; i++) {
        bool v2 = array[3];
        if (v != v2) {
            printf("Word-Tearing found: array[%lu] = %c, should be %c", mythid, v2, v);
            fflush(stdout);
            exit(0);
        }
        v = !v;
        array[3] = v;
    }
    printf("Done %lu\n", mythid);
    return NULL;
}

int main() {
    pthread_t thid, mythid;
    int result = pthread_create(&thid, (pthread_attr_t *) NULL, mythread, NULL);
    if (result != 0) {
        printf("Error on thread create, return value = %d\n", result);
        exit(1);
    }
    printf("Thread created, thid %lu\n", thid);
    mythid = pthread_self();
    int i;
    bool v = false;
    for (i = 0; i < ITERS; i++) {
        bool v2 = array[0];
        if (v != v2) {
            printf("Word-Tearing found: array[%lu] = %c, should be %c", mythid, v2, v);
            fflush(stdout);
            exit(0);
        }
        v = !v;
        array[0] = v;
    }
    printf("Done %lu\n", mythid);
    pthread_join(thid, (void **) NULL);
    printf("Done all\n");
    return 0;
}
