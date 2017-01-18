#include <stdio.h>
#include <stdbool.h>

int solution(int N) {
  int number = N;
  int answer = 0;
  int current_digit;
  bool state_in_gap = false;
  int current_length = 0;

  //while (number > 0) {
  for (int i = 0; i < 32; i++) {
    // find current binary digit
    current_digit = ((number & (1 << i))>0)?1:0;
    //number = number >> 1;
    //printf("current=%d\n",current_digit);
    // check state
    if (state_in_gap) {
      if (current_digit == 1) {
        //state_in_gap = false;
        if (current_length > answer) {
          answer = current_length;
	}
        current_length = 0;
      } else {
        current_length = current_length + 1;
      }
    } else {
      // not in gap
      if (current_digit == 1) {
        state_in_gap = true;
      } else {
        // pass
      }
    }
  }
  return answer;
}

int main() {
  int ans = solution(1376796946);
  printf("%d\n", ans);
  return 0;
}
