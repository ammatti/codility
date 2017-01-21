#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strlen()

#define XOR_SWAP(a, b) \
  do {                 \
    a ^= b;            \
    b ^= a;            \
    a ^= b;            \
  } while (0)

void reverse_str(char *source, char *destination) {
  int length = 0;
  if (source) {
    length = strlen(source);
    char* dst_index = destination + length;
    // end of string
    *dst_index = '\0';
    dst_index--;
    for (int i = (length - 1); i >= 0; i--) {
      //printf("%d = %c\n",i, *source);
      *dst_index = *source;
      source++;
      dst_index--;
    }
  }
}

void inplace_reverse_str(char *source) {
  if (source) {
    char *end = source + strlen(source) - 1;
    while (source < end) {
      XOR_SWAP(*source, *end);
      source++;
      end--;
    }
  }
}

int main() {
  char str[] = "helloworld";
  printf("%s\n", str);
  inplace_reverse_str(str);
  printf("%s\n", str);

  //2nd method
  int length = strlen(str);
  char *origin = (char*)malloc(length+1);
  reverse_str(str, origin);
  printf("%s\n", origin);
  free(origin);
  return 0;
}
