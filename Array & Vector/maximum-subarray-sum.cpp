#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int MaximumSubarraySum(vector<int> arr, int n, int i = 0) {
  if (n == 0) {
    return arr[0];
  }
  int sum = MaximumSubarraySum(arr, n - 1, i + 1);
  sum = max(sum, sum + arr[i]);
  return sum;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
  int n = arr.size();
  cout << MaximumSubarraySum(arr, n);
  cout << endl;
  return 0;
}
