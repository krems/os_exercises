#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const size_t BUF_SIZE = 1000;

int main() {
  const char* open_tag = "<b>";
  const char* close_tag = "</b>";
  char input[BUF_SIZE];
  size_t buf_size = BUF_SIZE + strlen(open_tag) + strlen(close_tag);
  char buf[buf_size];
  while (scanf("%s", input) == 1) {
    strncpy(buf, open_tag, buf_size);
    strncat(buf, input, buf_size);
    strncat(buf, close_tag, buf_size);
    printf("%s\n", buf);
  }
  return 0;
}
