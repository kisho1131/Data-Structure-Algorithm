#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void RainWaterTapping(int arr[], int n) {
  int mxL[n];
  int mxR[n];
  int water[n];
  int sum = 0;
  if (n == 0) {
    cout << sum;
    return;
  }

  mxL[0] = arr[0];
  mxR[n - 1] = arr[n - 1];
  for (int i = 1; i < n; i++) {
    mxL[i] = max(mxL[i - 1], arr[i]);
  }
  for (int i = n - 2; i >= 0; i--) {
    mxR[i] = max(mxR[i + 1], arr[i]);
  }
  for (int i = 0; i < n; i++)
    water[i] = min(mxL[i], mxR[i]) - arr[i];
  for (int i = 0; i < n; i++)
    sum += water[i];
  cout << sum;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {3, 0, 0, 2, 0, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  RainWaterTapping(arr, n);
  cout << endl;
  return 0;
}
