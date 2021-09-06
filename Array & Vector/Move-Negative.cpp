#include <bits/stdc++.h>
using namespace std;

// Two Pointer Approch --> Important For the Coding Round for the Big Companies

void Rearrange(int arr[], int n) {
  int left = 0;
  int right = n - 1;
  for (int i = 0; i < n; i++) {
    if (arr[left] < 0 && arr[right] < 0)
      left++;
    if (arr[left] > 0 && arr[right] < 0) {
      swap(arr[left], arr[right]);
      left++;
      right--;
    }
    if (arr[left] > 0 && arr[right] > 0)
      right--;
  }
}

// Second Approch O(N):
//  This Approh is Similar to the Quick Sort Approch Here 0 is the Privot
//  Element

void Rearrange_Approch_2(int arr[], int n) {
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      if (j != i)
        swap(arr[i], arr[j]);
      j++;
    }
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
  int n = sizeof(arr) / sizeof(arr[0]);
  Rearrange_Approch_2(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
