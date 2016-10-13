#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[], char* envp[]) {
  char** env;
  for (env = envp; *env != 0; env++) {
    char* cur = *env;
    printf("%s\n", cur);    
  }
  return 0;
}


void uids() {
  printf("%d %d\n", getuid(), getgid());
  setuid(0);
  setgid(0);
  printf("%d %d\n", getuid(), getgid());
  return 0;
}
