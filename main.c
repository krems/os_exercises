#include <pthread.h>
#include <stdio.h>

void* printCurrentThreadId(void*);

int main() {
    printCurrentThreadId("main");
    pthread_t tid = 0;
    pthread_t tid2 = 0;
    pthread_create(&tid, NULL, printCurrentThreadId, "child");
    pthread_create(&tid2, NULL, printCurrentThreadId, "child2");
    printCurrentThreadId("main2");
    pthread_join(tid, NULL);
    char* result;
    pthread_join(tid2, (void **) &result);
    printf("tid: %ld\n", tid);
    printf("tid2: %ld\n", tid2);
    printf("result: %s\n", result);
    return 0;
}

void* printCurrentThreadId(void* arg) {
    char* t_name = (char*) arg;
    pthread_t tid = pthread_self();
    printf("%s: %ld\n", t_name, tid);
    return "PREVED";
}
