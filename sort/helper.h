void swap(int arr[], int indexOne, int indexTwo) {
  int temp = arr[indexOne];
  arr[indexOne] = arr[indexTwo];
  arr[indexTwo] = temp;
}