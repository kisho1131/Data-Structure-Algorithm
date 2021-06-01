#include <bits/stdc++.h>
using namespace std;

void findMax(int arr[], int idx, int n, int &max) {
  if (idx == n)
    return;
  findMax(arr, idx + 1, n, max);
  if (arr[idx] > max)
    max = arr[idx];
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int max = INT_MIN;
  findMax(arr, 0, n, max);
  cout << max;
  return 0;
}
