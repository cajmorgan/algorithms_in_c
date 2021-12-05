#include <stdio.h>
#include "helper.h"

/** INSERTION SORT **\
 * Worst performace: 0(n²)
 * One of the shortest and easiest sorting algorithms
 * Starts by index 1 because the nested loop always compares the previous value. 
 * Subindex gets index and then loop subloop until subindex is 0 or "subindex value" is larger than "subindex - 1 value"
 * If "subindex - 1" value is larger than "subindex" value then swap and decrement subindex
 * index = 1;
 * subindex = 1;
 * [3, 2, 5, 1, 4];
 * 3 is larger than 2, swap and decrement subindex
 * [2, 3, 1, 1, 4]
 * next 
 * index = 2
 * subindex = 2
 * [2, 3, 1, 1, 4]
 * 3 is larger than 2, swap and decrement subindex
 * [2, 1, 3, 1, 4]
 * 2 is larger than 1, swap and decrement subindex
 * [1, 2, 3, 1, 4]
 *  
 * Repeat above process after incrementing index...
 * [1, 1, 2, 3, 4]
 * 
 * **/
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