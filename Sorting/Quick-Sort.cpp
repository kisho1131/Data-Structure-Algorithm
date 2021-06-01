#include <bits/stdc++.h>
using namespace std;

int Partation(int arr[], int s, int r) {
  int pivot = arr[r];
  int k = s - 1;
  for (int i = s; i <= r - 1; i++) {
    if (arr[i] <= pivot) {
      k = k + 1;
      swap(arr[k], arr[i]);
    }
  }
  swap(arr[k + 1], arr[r]);
  return k + 1;
}

void QuickSort(int arr[], int s, int r) {
  if (s >= r)
    return;
  int m = Partation(arr, s, r);
  QuickSort(arr, s, m - 1);
  QuickSort(arr, m + 1, r);
}

int main(int argc, char const *argv[]) {
  int arr[] = {5, 2, 1, 3, 7, 0, 10, 66, 3, 3, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  QuickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << "->";
  }
  return 0;
}
