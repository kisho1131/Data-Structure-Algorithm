#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

vector<int> leftArray(int arr[], int n) {
  stack<pair<int, int>> s;
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (s.size() == 0)
      res.push_back(-1);
    else if (s.size() > 0 && s.top().first < arr[i])
      res.push_back(s.top().second);
    else if (s.size() > 0 && s.top().first >= arr[i]) {
      while (s.size() > 0 && s.top().first >= arr[i])
        s.pop();
      if (s.size() == 0)
        res.push_back(-1);
      else
        res.push_back(s.top().second);
    }
    s.push(make_pair(arr[i], i));
  }
  return res;
}

vector<int> rightArray(int arr[], int n) {
  stack<pair<int, int>> s;
  int temp = n;
  vector<int> res;
  for (int i = n - 1; i >= 0; i--) {
    if (s.size() == 0)
      res.push_back(temp);
    else if (s.size() > 0 && s.top().first < arr[i])
      res.push_back(s.top().second);
    else if (s.size() > 0 && s.top().first > arr[i]) {
      while (s.size() > 0 && s.top().first > arr[i])
        s.pop();
      if (s.size() == 0)
        res.push_back(temp);
      else
        res.push_back(s.top().second);
    }
    s.push(make_pair(arr[i], i));
  }
  reverse(res.begin(), res.end());
  return res;
}

void maxAreaHistogram(int arr[], int n) {
  vector<int> left = leftArray(arr, n);
  vector<int> right = rightArray(arr, n);
  vector<int> width(n);
  vector<int> area(n);
  for (int i = 0; i < n; i++) {
    width[i] = right[i] - left[i] - 1;
  }
  for (int i = 0; i < n; i++) {
    area[i] = width[i] * arr[i];
  }
  cout << *max_element(area.begin(), area.end());
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  /*           0, 1, 2, 3, 4, 5, 6 */
  int arr[] = {2, 1, 5, 6, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  maxAreaHistogram(arr, n);
  cout << endl;
  return 0;
}
