#include <math.h>
#include <stdio.h>


/** BinarySearch algorithm for sorted arrays.
 * Best performance: O(1)
 * Worse performance: O(log(n))
 * if T ∈ {1,2,3,4,5,6,7,8}
 *  
 *         (4)
 *       /     \
 *    (2)      (6)
 *   /   \    /   \
 * (3)   (1)(5)   (7)
 *                   \
 *                   (8)
 * 
*/
int binarySearchIterations = 0;

int binarySearch(int arr[], int target, int low, int high, int index) {
  binarySearchIterations++;
  if (low > high) return -1;
  index = floor((low + high) / 2);
  if (arr[index] == target) return index;
  if (arr[index] < target) binarySearch(arr, target, index + 1, high, index);
  else if (arr[index] > target) binarySearch(arr, target, low, index - 1, index);
}

int main() {
  int arrToSearch[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int found = binarySearch(arrToSearch, 8, 0, 7, 0);
  printf("FOUND %d\n", found);
  printf("BinarySearch Performance: %d", binarySearchIterations);

}