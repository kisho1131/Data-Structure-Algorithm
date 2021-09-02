#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

// Brute Force Approch O(N^2)
pair<int, int> solution(int arr[], int sum, int n) {
  pair<int, int> p;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] + arr[j] == sum) {
        p.first = i;
        p.second = j;
        return p;
      }
    }
  }
  return make_pair(0, 0);
}

// Optimized Approch O(N) Solution

vector<int> OptimizedPairSum(int *arr, int sum, int n) {
  unordered_set<int> s;
  vector<int> result;
  for (int i = 0; i < n; i++) {
    int x = sum - arr[i];
    if (s.find(x) != s.end()) {
      result.push_back(x);
      result.push_back(arr[i]);
      return result;
    }
    s.insert(arr[i]);
  }
  return result;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int *arr = new int(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int sum = 4;
  pair<int, int> p = solution(arr, sum, n);
  cout << arr[p.first] << "-" << arr[p.second];
  cout << endl;
  vector<int> result = OptimizedPairSum(arr, sum, n);
  for (auto x : result) {
    cout << x << "->";
  }
  return 0;
}
