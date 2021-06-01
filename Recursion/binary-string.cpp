/* Q. Generate all the Binary String of lenth N
eg: N= 2 String = 00 01 10 11

*/
#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void printArray(vector<int> arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  // cout << endl;
}
void BinaryString(int n, string arr, int i) {
  if (i == n) {
    cout << arr << " ";
    cout << endl;
    return;
  }
  arr[i] = 0;
  BinaryString(n, arr + "0", i + 1);
  arr[i] = 1;
  BinaryString(n, arr + "1", i + 1);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  // vector<int> arr(n);
  BinaryString(n, "", 0);
  cout << endl;
  return 0;
}
