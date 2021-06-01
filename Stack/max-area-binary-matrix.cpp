#include <bits/stdc++.h>
using namespace std;
/*=========== Your Code Here =============*/

vector<int> leftArray(vector<int> arr, int n) {
  vector<int> left;
  stack<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    if (s.size() == 0)
      left.push_back(-1);
    else if (s.size() > 0 && s.top().first < arr[i])
      left.push_back(s.top().second);
    else if (s.size() > 0 && s.top().first >= arr[i]) {
      while (s.size() > 0 && s.top().first >= arr[i])
        s.pop();
      if (s.size() == 0)
        left.push_back(-1);
      else
        left.push_back(s.top().second);
    }
    s.push(make_pair(arr[i], i));
  }
  return left;
}

vector<int> rightArray(vector<int> arr, int n) {
  stack<pair<int, int>> s;
  vector<int> right;
  for (int i = n - 1, i >= 0; i--) {
    if (s.size() == 0)
      rigth.push_back(n);
    else if (s.size() > 0 && s.top().first > arr[i])
      right.push_back(s.top().second);
    else if (s.size() > 0 && s.top().first <= arr[i]) {
      while (s.size() > 0 && s.top().first <= arr[i])
        s.pop();
      if (s.size() == 0)
        right.push_back(n);
      else
        right.push_back(s.top().second);
    }
    s.push(make_pair(arr[i], i));
  }
  reverse(right.begin(), right.end());
  return right;
}

int MAH(vector<int> arr, int n) {
  vector<int> left = leftArray(arr, n);
  vector<int> right = rightArray(arr, n);
  vector<int> width;
  vector<int> area;
  for (int i = 0; i < n; i++) {
    width[i] = right[i] - left[i] - 1;
  }
  for (int i = 0; i < n; i++) {
    area[i] = arr[i] * width[i];
  }
  int maxArea = *max_element(area.begin(), area.end());
  return maxArea;
}

void maxAreaRectangle(vector<vector<int>> &arr, int n) {
  int mx;
  vector<int> v;
  for (int j = 0; j < n; j++)
    v.push_back(arr[0][j]);
  mx = MAH(v);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 0)
        v[j] = 0;
      else
        v[j] = v[j] + arr[i][j];
    }
  }
  int ans = max(mx, MAH(v));
  cout << ans << " ";
}

/*============ Main() ====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr;
  int n;
  cin >> n;
  maxAreaRectangle();
  cout << endl;
  return 0;
}
