#include <stdio.h>

/** A bit better sort than O(n²)*/
int cajSortIterations = 0;

void cajSort(int arr[], int length) {
  int change = 1;
  while(change) {
    for (int i = 0; i < length; i++) {
      cajSortIterations++;
      if (i == 0)
        change = 0;

      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        change = 1;
      }
    }
  }

} 
