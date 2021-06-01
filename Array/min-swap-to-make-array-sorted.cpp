#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int MinSwap(vector<int> arr) {
  int ans = 0;
  map<int, int> mp;
  vector<int> temp = arr;
  for (int i = 0; i < arr.size(); i++) {
    mp[arr[i]] = i;
  }
  sort(temp.begin(), temp.end());
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] != temp[i]) {
      ans++;
      int idx = mp[temp[i]];
      // cout << idx << " ";
      swap(arr[i], arr[idx]);
      mp[temp[i]] = i;
    }
  }
  return ans;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr{5, 2, 6, 4, 1, 3};
  cout << MinSwap(arr);
  cout << endl;
  return 0;
}
