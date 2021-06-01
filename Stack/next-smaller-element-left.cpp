#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

vector<int> nextSmallerElementLeft(int arr[], int n) {
  vector<int> v;
  stack<int> s;
  for (int i = 0; i < n; i++) {
    if (s.empty())
      v.push_back(-1);
    else if (s.size() > 0 && s.top() > arr[i]) {
      while (s.size() > 0 && s.top() > arr[i])
        s.pop();
      if (s.empty())
        v.push_back(-1);
      else
        v.push_back(s.top());
    } else if (s.size() > 0 && s.top() < arr[i])
      v.push_back(s.top());
    s.push(arr[i]);
  }
  return v;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 3, 0, 0, 1, 2, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  vector<int> res = nextSmallerElementLeft(arr, n);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
