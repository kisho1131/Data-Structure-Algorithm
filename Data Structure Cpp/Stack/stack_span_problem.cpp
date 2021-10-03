#include<bits/stdc++.h>
using namespace std;

vector<int> stock_span(int arr[], int n) {
  vector<int>v;
  stack<pair<int, int> >s;
  for (int i = 0; i < n; i++) {
    // int count = 1;
    if (s.empty())
      v.push_back(-1);
    else if (s.size() > 0 && arr[i] < s.top().first)
      v.push_back(s.top().second);
    else if (s.size() > 0 && s.top().first <= arr[i]) {
      while (s.size() > 0 && s.top().first <= arr[i]) {
        s.pop();
      }
      if (s.empty())
        v.push_back(-1);
      else
        v.push_back(s.top().second);
    }
    s.push(make_pair(arr[i], i));
  }
  return v;
}

int main(int argc, char const *argv[]) {

  int arr[] = {100, 80, 60, 70, 60, 75, 85};
  int n = sizeof(arr) / sizeof(arr[0]);
  vector<int>v;
  v = stock_span(arr, n);
  for (int i = 0; i < n; i++) {
    v[i] = i - v[i];
  }
  for (auto x : v) {
    cout << x << " ";
  }
  return 0;
}
