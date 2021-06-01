#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void targetSubsetSum(vector<int> arr, int idx, string set, int sum,
                     int tarSum) {
  if (arr.size() == idx) {
    if (sum == tarSum) {
      cout << set << " " << endl;
    }
    return;
  }
  targetSubsetSum(arr, idx + 1, set + to_string(arr[idx]) + ", ",
                  sum + arr[idx], tarSum);
  targetSubsetSum(arr, idx + 1, set, sum, tarSum);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int tarSum = 0;
  cin >> tarSum;
  targetSubsetSum(arr, 0, "", 0, tarSum);
  cout << endl;
  return 0;
}
