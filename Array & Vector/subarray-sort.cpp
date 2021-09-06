#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

/* Time Complexity is O(NLogN)
   Approch is to sort the array and compare the orignal and the sorted array
*/
vector<int> SubarrySort_BrutForce(vector<int> arr) {
  vector<int> arrTemp(arr);
  sort(arrTemp.begin(), arrTemp.end());
  int n = arr.size();
  int i = 0;
  while (i < n and arr[i] == arrTemp[i])
    i++;
  int j = n - 1;
  while (j >= 0 and arr[j] == arrTemp[j])
    j--;
  if (i == n) {
    return {-1, -1};
  }
  return {i, j};
}

/* Optimized Solutions */

bool outOfOrder(vector<int> arr, int index) {
  int x = arr[index];
  if (index == 0)
    return x > arr[1];
  if (index == arr.size() - 1)
    return x < arr[index - 1];
  return (x < arr[index - 1]) or (x > arr[index + 1]);
}
pair<int, int> SubarrySort(vector<int> arr) {
  int smallest = INT_MAX;
  int largest = INT_MIN;
  for (int i = 0; i < arr.size(); i++) {
    int x = arr[i];
    if (outOfOrder(arr, i)) {
      smallest = min(smallest, x);
      largest = max(largest, x);
    }
  }
  if (smallest == INT_MAX) {
    return {-1, -1};
  }
  int left = 0;
  while (smallest >= arr[left])
    left++;
  int right = arr.size() - 1;
  while (largest <= arr[right])
    right--;
  return {left, right};
}
/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
  vector<int> ans = SubarrySort_BrutForce(arr);
  for (auto ele : ans) {
    cout << ele << " ";
  }
  cout << endl;
  cout << "Optimized Solution:" << endl;
  pair<int, int> indexs = SubarrySort(arr);
  cout << indexs.first << " " << indexs.second;
  cout << endl;
  return 0;
}
