/* ARRAYS TO TEST WITH */
#include "quicksort.c"

int arr26[] = {3, 7, 8, 5, 2, 1, 9, 5, 4, 4, 7, 8, 10, 12, 3, 2, 1, 55, 6, 8, 4, 2, 3, 4, 5, 6};
int arr7[] = {3, 7, 8, 5, 2, 1, 9, 5, 4};


int *cpyArr() {

}

int main () {
  // int arrToSort[] = {3, 7, 8, 5, 2, 1, 9, 5, 4};
int arrToSort[] = {1,2,4,3};
  quickSort(arrToSort, 0, 3);
  for (int i = 0; i < 4; i++) {
    printf("%d, ", arrToSort[i]);
  }

  // printf("\nQuickSort Performance %d", quickSortIterations);
}