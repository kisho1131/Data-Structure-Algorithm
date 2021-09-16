#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

/* Brute Force Solution --> Approch 1
 * Time Complexity = O(N^2)
 * Space Complexity = O(1)
 */

int MaximumSubarraySum(vector<int> arr) {
  int sum = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int currSum = 0;
    currSum += arr[i];
    for (int j = i + 1; j < n; j++) {
      currSum += arr[j];
      if (currSum > sum)
        sum = currSum;
    }
  }
  return sum;
}

/* Approch 2 --> Optimized Solution */
int KadansAlgorithm(vector<int> arr) {
  int sum = 0;
  int maxSum = INT_MIN;
  for (auto ele : arr) {
    sum += ele;
    maxSum = max(sum, maxSum);
    if (sum < 0)
      sum = 0;
  }
  return maxSum;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
  cout << MaximumSubarraySum(arr) << endl;
  cout << KadansAlgorithm(arr);
  cout << endl;
  return 0;
}
