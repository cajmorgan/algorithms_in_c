#include <stdio.h>
#include <stdlib.h>

void split_merge(int A[], int start, int end);
void sort_splits(int A[], int start, int middle, int end);
void merge_sort(int A[], int length) {
  int B[length];

  split_merge(A, 0, length);
};

/** 
 * Ex. [0, 2] [1, 4]
 * left_arrow = start, right_arrow = middle
 * check smallest, push to temp, increase that one.
 * 
 *  **/
void sort_splits(int A[], int start, int middle, int end) {
  int left_arrow = start;
  int right_arrow = middle;
  int picker = 0;
  int temp_arr[end - start];

  while(right_arrow < end || left_arrow < middle) {
    if ((A[left_arrow] <= A[right_arrow] || right_arrow >= end) && left_arrow < middle) {
      temp_arr[picker++] = A[left_arrow];
      left_arrow++;
    } else if ((A[right_arrow] <= A[left_arrow] || left_arrow >= middle) && right_arrow < end) {
      temp_arr[picker++] = A[right_arrow];
      right_arrow++;
    }
  }

  int a_counter = start;
  for (int i = 0; i < end - start; i++) {
    A[a_counter++] = temp_arr[i];
  }


}

void split_merge(int A[],  int start, int end) {
  if (end - start <= 1)
    return;

  int middle = (start + end) / 2;

  split_merge(A, start, middle);
  split_merge(A, middle, end);

  sort_splits(A, start, middle, end);
}


int main() {
  int arr_to_sort[] = {0, 4, 2, 7, 2, 9, 12, 3};
  int length = 8;
  merge_sort(arr_to_sort, length);

  for (int i = 0; i < 8; i++) {
    printf("%d\n", arr_to_sort[i]);
  }

}