#include <stdio.h>
#include "helper.h"

/** Shell sort 
 * I came across this interesting algorithm while doing the K&R excercises. 
 * Though the below implementation is mostly inspired from the Wikipedia article of shell sort with some changes, 
 * it still opened my eyes to how 3 subloops can be much more effecient than a nested two loop O(n²) sorting algorithm.
 * 
 * This algorithms efficiency is very much dependent on the gaps and how big and many they are depending on n size of unsorted array. 
 * The most outer loop decides which gap value we will use. 
 * The first subloop is interesting as it will do the offset in the array. The interesting part is the 'offset < gaps', 
 * Why? Well if we look at the next inner loop, that one will grab every value separated by the chosen gap 'i += gap'
 * This means that we get a kind of reverse modulu operation happening at the first subloop where it will only continue until offset is >= gapIndex.
 * So if we have [1, 3, 6, 7, 2, 9] with a gap of two, together with the inner loop, all numbers will be checked by just looping until the said requirement.
 * As already mentioned, the next subloop will check every index % gap and only skip remainders which will be handled on iterations when gap is lowered.
 * Gap is apparently most effiecient when divided by around 2.25, gap ∈ [701, 311, 138, 69, 34, 17, 8, 4, 2, 1] (U)
 * The most inner while loop, performs a normal insertion sort but instead of comparing stepwise, it will compare using gaps.
 * If the subarray [1, 6, 2] ⊆ U 
 * Checks, is 1(- gaps[gapIndex]) larger than 6 (gaps[gapIndex]? No, increase i += gaps[gapIndex]
 * is 6 larger than 2? Yes, swap 6 and 2 [1, 2, 6]
 * Etc etc. 
 * 
 * This is a beautiful and compact but still advanced sorting algorithm. At first glance without the knowledge, 
 * it might look suprisingly ineffcient. But as soon as you understand how it works, it's really cool!
 * An array of 16 values could be sorted with only a total of 56 iterations around O(n² * n), comparable to 256 with O(n²)
 * 
 * **/

int shellSortIterations = 0; //Just for measuring 
void shellsort(int arr[], int length) {
  int gaps[] = { 5, 3, 1 };
  for (int gapIndex = 0; gapIndex < 3; gapIndex++) {
    for (int offset = 0; offset < gaps[gapIndex]; offset++) {
      for (int i = offset + gaps[gapIndex]; i < length; i += gaps[gapIndex]) {
        shellSortIterations++;
        int temp = i + gaps[gapIndex];
        while (temp > 0 && temp < length && arr[temp - gaps[gapIndex]] > arr[temp]) {
          swap(arr, temp, temp - gaps[gapIndex]);
          temp -= gaps[gapIndex];
          shellSortIterations++;
        }
      }
    }
  }
}


int main() {
  int input[] = { 3, 2, 7, 5, 2, 9, 23, 53, 1, 23, 43, 57, 95, 67, 23, 54 };
  int length = 16;
  shellsort(input, length);

  for (int i = 0; i < 16; i++) {
    printf("%d\n", input[i]);
  }

  printf("ITERATIONS: %d", shellSortIterations);

}