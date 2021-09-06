#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int MountainSolution(vector<int> arr) {
  int longest = 0;
  int n = arr.size();
  for (int i = 1; i <= n - 2;) {
    if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
      int count = 1;
      // Backword Count - left
      int j = i;
      while (j >= 1 && arr[j] > arr[j - 1]) {
        count++;
        j--;
      }
      // Forward Count - Right
      while (i <= n - 2 && arr[i] > arr[i + 1]) {
        count++;
        i++;
      }
      longest = max(longest, count);
    } else {
      i++;
    }
  }
  return longest;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
  int ans = MountainSolution(arr);
  cout << ans;
  cout << endl;
  return 0;
}
