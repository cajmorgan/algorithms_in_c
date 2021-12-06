#include <stdio.h>
#include "helper.h"

/** Shell sort **/
int shellSortIterations = 0;
void shellsort(int arr[], int length) {
  int gaps[] = { 5, 3, 1 };
  for (int gapIndex = 0; gapIndex < 3; gapIndex++) {
    for (int offset = 0; offset < gaps[gapIndex]; offset++) {
      for (int i = offset; i < length; i += gaps[gapIndex]) {
        shellSortIterations++;
        int temp = i + gaps[gapIndex];
        while (temp > 0 && temp < length && arr[temp - gaps[gapIndex]] > arr[temp]) {
          swap(arr, temp, temp - gaps[gapIndex]);
          temp -= gaps[gapIndex];
          shellSortIterations++;
        }
      }
    }
  }
}


int main() {
  int input[] = { 3, 2, 7, 5, 2, 9, 23, 53, 1, 23, 43, 57, 95, 67, 23, 54 };
  int length = 16;
  shellsort(input, length);

  for (int i = 0; i < 16; i++) {
    printf("%d\n", input[i]);
  }

  printf("ITERATIONS: %d", shellSortIterations);

}