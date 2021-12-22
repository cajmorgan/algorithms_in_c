#include <stdio.h>
#include "helper.h"


/** QUICKSORT 
 * Effeciency: O(nlog2n)
 * worse case: O(n²)
 * 
 * Partioning
 * Places a pivot always as the highest point in the 'subarray'
 * [5, 3, 1, 2(p)]
 * While the index of pivot is larger than incrementer, continue loop.
 * if value of increment index is smaller than pivot, simply increase increment index by 1
 * else swap the values of increment index(0) with value of index before pivot(2) 
 * and then swap pivot with the new value on the index before pivot, pivot index get decremented by 1.
 * 1  [5, 3, 1, 2(p)] (original subarray)
 * 1. [1, 3, 5, 2(p)]
 * 2. [1, 3, 2(p), 5]
 * Increment index ONLY gets incremented if value of it is smaller than value of pivot index
 * When value of increment index is larger or equal to pivot index, return pivot index.
 * 
// */

int quickSortIterations = 0;
int partion(int arr[], int low, int high) {
  int pivotIndex = high;
  int pivot = arr[pivotIndex];
  int j = 0;

  while (pivotIndex > j) {
    quickSortIterations++;
    if (arr[j] > pivot) {
      swap(arr, j, pivotIndex-1);
      swap(arr, pivotIndex - 1, pivotIndex);
      pivotIndex--;
      continue;
    }

    j++;
  }
  
  return pivotIndex;
}

/** Takes low and high index args for array
 *  Uses an offset of pivot index recursively to sort subarrays of original array, until low(index) is equal to (or larger than) high(index)
 *  Breaks up current array into two smaller pieces where pivot index - 1 is the largest index 
 *  for the smaller valued array and pivotindex + 1 is the smallest index for the larger valued array.
 *  As said, it will continue breaking down the array into smaller pieces until low is equal to or larger than high.
 *  This makes quicksort much more effecient than f.e insertionsort that have to loop through the array with a worse performance of O(n²)
 *  or a nested increment O(n²) sort for that matter.
 *  **/

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivotIndex = partion(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  } 
}

