/* Band: subsequence which can be recorded in such a manner as the element
 *
 * appear consecutive (i.e with the absolute difference of 1 b/w neighbour
 *
 * element) */

#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int LongestBand(vector<int> arr) {
  int n = arr.size();
  unordered_set<int> s;
  for (auto x : arr) {
    s.insert(x);
  }
  int largestBand = 0;
  for (auto ele : s) {
    int parent = ele - 1;
    if (s.find(parent) == s.end()) {
      int next_no = ele + 1;
      int count = 1;
      while (s.find(next_no) != s.end()) {
        next_no++;
        count++;
      }
      largestBand = max(largestBand, count);
    }
  }
  return largestBand;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
  cout << LongestBand(arr);
  return 0;
}
