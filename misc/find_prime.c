#include <stdio.h>
#include <stdbool.h>

bool is_prime(int number) {
  bool result = true;
  for (int count = 2; count <= (number / 2); count++) {
    if (number % count == 0) {
      result = false;
      break;
    }
  }
  return result;
}

int main() {
  for (int i = 2; i <= 100; i++) {
    bool prime = is_prime(i);
    if (prime) {
      printf("%d\n", i);
    }
  }
  return 0;
}
