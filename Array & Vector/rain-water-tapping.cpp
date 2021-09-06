/* Given n non-negative integers representing an elevation map where the width
of each bar is 1, compute how much water it can tap after raining*/

#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int RainWaterTapping(vector<int> heights) {
  int water = 0;
  int n = heights.size();
  if (n <= 2)
    return 0;
  vector<int> left(n, 0), right(n, 0);
  left[0] = heights[0];
  right[n - 1] = heights[n - 1];
  for (int i = 1; i < n; i++) {
    left[i] = max(left[i - 1], heights[i]);
    right[n - 1 - i] = max(right[n - i], heights[n - i - 1]);
  }
  for (int i = 0; i < n; i++) {
    water += min(left[i], right[i]) - heights[i];
  }
  return water;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << RainWaterTapping(heights);
  cout << endl;
  return 0;
}
