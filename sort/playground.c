/* ARRAYS TO TEST WITH */
#include "quicksort.c"

int arr26[] = {3, 7, 8, 5, 2, 1, 9, 5, 4, 4, 7, 8, 10, 12, 3, 2, 1, 55, 6, 8, 4, 2, 3, 4, 5, 6};
int arr7[] = {3, 7, 8, 5, 2, 1, 9, 5, 4};


int *cpyArr() {

}

int main () {
  // int arrToSort[] = {3, 7, 8, 5, 2, 1, 9, 5, 4};
int arrToSort[] = { 3, 2, 7, 5, 2, 9, 23, 53, 1, 23, 43, 87 };
  quickSort(arrToSort, 0, 11);
  for (int i = 0; i < 12; i++) {
    printf("%d, ", arrToSort[i]);
  }

  printf("\nQuickSort Performance %d", quickSortIterations);
}