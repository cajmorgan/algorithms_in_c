#include <stdio.h>

/** O(nlog2n)*/
int quickSortIterations = 0;

int partion(int arr[], int low, int high) {
  int pivotIndex = high;
  int pivot = arr[pivotIndex];
  int j = 0;

  while (pivotIndex > j) {
    quickSortIterations++;
    if (arr[j] > pivot) {
      arr[pivotIndex] = arr[j];
      arr[j] = arr[pivotIndex - 1];
      arr[pivotIndex - 1] = pivot;
      pivotIndex--;
      continue;
    }

    j++;
  }
  
  return pivotIndex;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivotIndex = partion(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  } 
}

