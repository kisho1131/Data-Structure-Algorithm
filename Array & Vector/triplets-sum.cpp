#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
vector<vector<int>> TripletSum(vector<int> arr, int targetSum) {
  int n = arr.size();
  vector<vector<int>> result;
  sort(arr.begin(), arr.end());
  for (int i = 0; i <= n - 3; i++) {
    int j = i + 1;
    int k = n - 1;
    while (j < k) {
      int current_sum = arr[i];
      current_sum += arr[j];
      current_sum += arr[k];
      if (current_sum == targetSum) {
        result.push_back({arr[i], arr[j], arr[k]});
        j++;
        k--;
      } else if (current_sum > targetSum)
        k--;
      else
        j++;
    }
  }
  return result;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
  int targetSum = 18;
  vector<vector<int>> ans = TripletSum(arr, targetSum);
  for (auto x : ans) {
    for (auto ele : x) {
      cout << ele << " ";
    }
    cout << endl;
  }
  return 0;
}
