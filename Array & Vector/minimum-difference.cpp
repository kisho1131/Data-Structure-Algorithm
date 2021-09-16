#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
pair<int, int> minDifference(vector<int> a, vector<int> b) {
  int n = a.size();
  int diff = INT_MAX;
  int index1 = -1;
  int index2 = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int curr_diff = a[i] - b[j];
      if (abs(curr_diff) < abs(diff)) {
        index1 = i;
        index2 = j;
        diff = curr_diff;
      }
    }
  }
  return {a[index1], b[index2]};
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> a = {23, 5, 10, 17, 30};
  vector<int> b = {26, 134, 135, 14, 19};
  pair<int, int> p = minDifference(a, b);
  cout << p.first << " " << p.second;
  cout << endl;
  return 0;
}
