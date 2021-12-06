#include <stdio.h>
#include "helper.h"

void shellsort(int arr[], int length) {
  int gaps[] = { 5, 3, 1};
  int gapIndex = 0;
  for (int offset = 0; offset < gaps[gapIndex]; offset++) {
    for (int i = 0; i < length; i += gaps[gapIndex]) {
      
    }
  }

}


int main() {
  int input[] = { 3, 2, 7, 5, 2, 9, 23, 53, 1, 23, 43, 87 };
  int length = 5;
  shellsort(input, length);

  for (int i = 0; i < length; i++) {
    printf("%d", input[i]);
  }

}