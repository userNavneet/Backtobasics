 // Quick Sort implementation in C
#include <stdio.h>
void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
int main(int argc, char *argv[]) {
  int arr[] = {4, 3, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, size - 1);
  for (int i = 0; i < size; i++) {
    printf("%d", arr[i]);
  }
  return 0;
}

void quickSort(int arr[], int start, int end) {
  if (end <= start)
    return;
  int pivot = partition(arr, start, end);
  quickSort(arr, start, pivot - 1);
  quickSort(arr, pivot + 1, end);
}
int partition(int arr[], int start, int end) {
  int i = start - 1;
  int pivot = arr[end];
  for (int j = start; j <= end; j++) {
    if (arr[j] < pivot) {
      i++;
      int tmp = arr[j];
      arr[j] = arr[i];
      arr[i] = tmp;
    }
  }
  i++;
  int tmp = arr[end];
  arr[end] = arr[i];
  arr[i] = tmp;
  return i;
}