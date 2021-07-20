#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int CollectCoin(vector<int> arr) {
  int sum = 0;
  int n = arr.size();
  int i = 0;
  while (1) {
    if (arr[i] == 0)
      break;
    if (arr[i] != 0) {
      --arr[i];
      sum++;
    }
    i = ((i + 1) % n);
  }
  return sum;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {3, 2, 1, 7};
  int sum = CollectCoin(arr);
  cout << sum;
  cout << endl;
  return 0;
}
