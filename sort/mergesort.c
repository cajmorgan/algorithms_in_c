#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter = 0;

void split_merge(int A[], int temp_arr[], int start, int end, int org_length);
void sort_splits(int A[], int temp_arr[], int start, int middle, int end, int org_length);
void merge_sort(int A[], int length) {
  int B[length];
  int org_length = length;

  int temp_arr[org_length];
  memcpy(temp_arr, A, sizeof(int) * org_length);
  split_merge(A, temp_arr, 0, length, org_length);
};

/** 
 * Best case performance: Ω(n)
 * General performance: O(log2(n/2))
 * Worse case performance: O(log2n)
 * Ex. Arr1[0, 2] Arr2[1, 4]
 * left_arrow = start, right_arrow = middle(start of Arr2)
 * check smallest, push to temp, move that arrow one step to right.
 * Example:
 * TempArr = [0, 2, 1, 4]
 * Arr1 = [0, 2] 
 * Arr2 = [1, 4]
 * ***********
 * 1. 
 * [*0*, 2] [*1*, 4]
 * [*0*, 2, 1, 4] 
 * 2.
 * [0, *2*] [*1*, 4]
 * [0, *1*, 1, 4] 
 * 3.
 * [0, *2*] [1, *4*]
 * [0, 1, *2*, 4] 
 * 4.
 * [0, 2*]* [1, *4*]
 * [0, 1, 2, *4*] 
 * 
 * Now copy temp_arr to original arr sent in.
 * 
 * Without optimization the performance will always be O(log2n * n)
 * With optimization we can get Ω(n) in certain scenarios.
 * Optimization implemented: 
 * As both subarrays will guaranteed be sorted by themselves, 
 * we can check for the last value in the first array.
 * [0, *2*]
 * if that value is smaller than [*1*, 4] (which it isn't in this case)
 * we can break just merge the arrays, as they will already be sorted between each other.
 * 
 * A second optimization we can do is checking if the current right_arrow value 
 * is larger than last value of Arr1(middle-1) && left_arrow has incremented to middle. 
 * In that case, we know that the following right_arrow values will be higher, and therefore 
 * already are in the correct places in the A array. Break the loop. 
 *  **/
void sort_splits(int A[], int temp_arr[], int start, int middle, int end, int org_length) {
  int left_arrow = start;
  int right_arrow = middle;
  int picker = start;
  
  while(right_arrow < end || left_arrow < middle) {
    if (A[middle-1] < A[middle]) 
      break;
    
    if (A[middle-1] < A[right_arrow] && left_arrow >= middle)
      break;
    
    counter++;
    if ((A[left_arrow] <= A[right_arrow] || right_arrow >= end) && left_arrow < middle) {
      temp_arr[picker++] = A[left_arrow];
      left_arrow++;
    } else if ((A[right_arrow] <= A[left_arrow] || left_arrow >= middle) && right_arrow < end) {
      temp_arr[picker++] = A[right_arrow];
      right_arrow++;
    }
  }

  memcpy(A, temp_arr, sizeof(int) * org_length);
}

void split_merge(int A[], int temp_arr[], int start, int end, int org_length) {
  if (end - start <= 1)
    return;

  int middle = (start + end) / 2;

  split_merge(A, temp_arr, start, middle, org_length);
  split_merge(A, temp_arr, middle, end, org_length);

  sort_splits(A, temp_arr, start, middle, end, org_length);
}


int main() {
  int arr_to_sort[] = {3,1,2,7,1,2,4,2,3,78,4,5};
  int length = 12;
  merge_sort(arr_to_sort, length);

  int arr_test[length];
  for (int i = 0; i < length; i++) {
    printf("%d\n", arr_to_sort[i]);
    // if (i == 0) {
    //   printf("{%d,", abs((i * rand()) % 100));
    //   continue;
    // } else if (i == 100000-1) {
    //   printf("%d}", abs((i * rand()) % 100));
    //   continue;
    // }

    // printf("%d,", abs((i * rand()) % 100));
  }


  printf("ITERATIONS: %d\n", counter);

}