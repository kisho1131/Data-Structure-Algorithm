#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

vector<int> stockSpanProblem(int arr[], int n) {
  // int count = 1;
  vector<int> res;
  Basr stack<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    if (s.size() == 0)
      res.push_back(-1);
    else if (s.size() > 0 && s.top().first > arr[i])
      res.push_back(s.top().second);
    else if (s.size() > 0 && s.top().first < arr[i]) {
      while (s.size() > 0 && s.top().first < arr[i])
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

/*============Main()====================*/

int main(int argc, char const *argv[]) {
  int arr[] = {100, 80, 60, 70, 60, 75, 85};
  int n = sizeof(arr) / sizeof(arr[0]);
  vector<int> res = stockSpanProblem(arr, n);
  for (int i = 0; i < n; i++) {
    res[i] = i - res[i];
  }
  for (auto ele : res) {
    cout << ele << " ";
  }
  cout << endl;
  return 0;
}
