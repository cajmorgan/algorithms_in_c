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
 * Ex. [0, 2] [1, 4]
 * left_arrow = start, right_arrow = middle
 * check smallest, push to temp, increase that one.
 * 
 *  **/
void sort_splits(int A[], int temp_arr[], int start, int middle, int end, int org_length) {
  int left_arrow = start;
  int right_arrow = middle;
  int picker = start;
  
  while(right_arrow < end || left_arrow < middle) {
    if (A[middle] > A[middle-1]) 
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
  int arr_to_sort[] = {16, 21, 32, 14, 16, 19, 20, 32, 12, 16 , 32, 12};
  int length = 12;
  merge_sort(arr_to_sort, length);

  int arr_test[12];
  for (int i = 0; i < 12; i++) {
    printf("%d\n", arr_to_sort[i]);
  }

  printf("ITERATIONS: %d\n", counter);

}