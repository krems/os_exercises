#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t lock;

int main() {
  if (pthread_mutex_init(&lock, NULL) != 0) {
    fprintf(stderr, "\n mutex init failed\n");
    perror("");
    exit(1);
  }
  pthread_mutex_lock(&lock);
  printf("a\n");
  pthread_mutex_unlock(&lock);
  pthread_mutex_destroy(&lock);
  return 0;
}
