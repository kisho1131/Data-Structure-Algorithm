#include <bits/stdc++.h>
using namespace std;
/*=========== Your Code Here =============*/

vector<int> nextGreaterElement(int arr[], int n) {
  stack<int> s;
  vector<int> res;
  for (int i = n - 1; i >= 0; i--) {
    if (s.size() == 0)
      res.push_back(-1);
    else if (s.size() > 0 && s.top() > arr[i]) {
      res.push_back(s.top());
    } else if (s.size() > 0 && s.top() < arr[i]) {
      while (s.size() > 0 && s.top() < arr[i]) {
        s.pop();
      }
      if (s.size() == 0)
        res.push_back(-1);
      else
        res.push_back(s.top());
    }
    s.push(arr[i]);
  }
  reverse(res.begin(), res.end());
  return res;
}

/*============ Main() ====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 3, 0, 0, 1, 2, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  vector<int> res = nextGreaterElement(arr, n);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
