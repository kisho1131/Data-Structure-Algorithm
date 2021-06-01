#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
  if (n == 1 || n == 0)
    return;

  for (int j = 1; j < n; j++) {
    int key = arr[j];
    int i = j - 1;
    while (i >= 0 && arr[i] > key) {
      arr[i + 1] = arr[i];
      i--;
      arr[i + 1] = key;
    }
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {5, 2, 1, 3, 7, 0, 10, 66, 3, 3, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  InsertionSort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
