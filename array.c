#include <stdlib.h>
#include <stdio.h>


void fill_array_from_keyboard(int32_t ar[], int32_t size) {
  int32_t i;
  for (i = 0; i < size; ++i) {
    scanf("%d", ar + i);
  }
}

void swap(int32_t* a, int32_t lhs, int32_t rhs) {
  int32_t tmp = a[lhs];
  a[lhs] = a[rhs];
  a[rhs] = tmp;
}

void insertion_sort(int32_t* a, int32_t n) {
  int32_t i;
  for (i = 1; i < n; ++i) {
    int32_t j = i;
    while (j > 0 && a[j - 1] > a[j]) { // push current to the left
      swap(a, j - 1, j);
      j--;
    }
  }
}
   
void print_array(int32_t ar[], int32_t size) {
  int32_t i;
  for (i = 0; i < size; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

int main() {
  int32_t size;
  scanf("%d", &size);
  int32_t* ar = (int32_t*) malloc(size * sizeof(int32_t));
  fill_array_from_keyboard(ar, size);
  insertion_sort(ar, size);
  print_array(ar, size);
  free(ar);
  return 0;
}

