#include <stdio.h>
#include "helper.h"

/**  */
void insertionsort(int arr[], int length) {
  for (int i = 1; i < length; i++) {
    int j = i;
    while(j > 0 && arr[j-1] > arr[j]) {
      swap(arr, j, j-1);
      j--;
    }
  }
}


int main() {
  int input[] = { 3, 2, 5, 1, 4 };
  int length = 5;
  insertionsort(input, length);

  for (int i = 0; i < length; i++) {
    printf("%d", input[i]);
  }

}