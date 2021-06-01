#include <bits/stdc++.h>
using namespace std;

// LeetCode Solutions --> Maximal Rectangle
// maximumAreaHistogram --> Maximal Rectangle Area
int maximumAreaHistogram(int arr[],
                         int m) { // maximumAreaHistogram MAH() function
  vector<int> right;
  vector<int> left;
  stack<pair<int, int>> s;
  for (int i = 0; i < m; i++) {
    while (!s.empty() && s.top().first >= arr[i]) // Next Smaller to Left
      s.pop();
    if (!s.empty())
      left.push_back(s.top().second);
    else
      left.push_back(-1);
    s.push({arr[i], i});
  }

  while (!s.empty()) // Empty the Stack
    s.pop();

  for (int i = m - 1; i >= 0; i--) { // Next Smaller to Right
    while (!s.empty() && s.top().first >= arr[i])
      s.pop();
    if (!s.empty())
      right.push_back(s.top().second);
    else
      right.push_back(m);
    s.push({arr[i], i});
  }
  reverse(right.begin(), right.end());
  int area;
  int mx = 0;
  for (int i = 0; i < m; i++) {
    area = arr[i] * (right[i] - left[i] - 1);
    mx = max(mx, area);
  }
  return mx;
}

// "0" & "1" are the string input in the Matrix;
int maximalRectangle(vector<vector<char>> &matrix) {
  if (matrix.size() == 0)
    return 0;

  int n = matrix.size();
  int m = matrix[0].size(); // No of Column
  int arr[m];
  for (int j = 0; j < m; j++)
    arr[j] = matrix[0][j] - '0';
  int ma = maximumAreaHistogram(arr, m);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == '0')
        arr[j] = 0;
      else
        arr[j] += (matrix[i][j] - '0');
    }
    ma = max(ma, maximumAreaHistogram(arr, m));
  }
  return ma;
}

int main(int argc, char const *argv[]) { return 0; }
