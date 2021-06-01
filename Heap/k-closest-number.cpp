/* Find k closest numbers in an unsorted array
Difficulty Level : Medium
Last Updated : 11 Feb, 2021
Given an unsorted array and two numbers x and k, find k closest values to x.
Examples:
Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3
Output : 4 6 7
Three closest values of x are 4, 6 and 7.

Input : arr[] = {-10, -50, 20, 17, 80}, x = 20, k = 2
Output : 17, 20 */

#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void KclosestElement(int arr[], int n, int k, int x) {
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; i++) {
    pq.push({abs(arr[i] - x), arr[i]});
    if (pq.size() > k)
      pq.pop();
  }
  while (!pq.empty()) {
    cout << pq.top().second << " ";
    pq.pop();
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {-10, -50, 20, 17, 80};
  int x = 20, k = 2;
  int n = sizeof(arr) / sizeof(arr[0]);
  KclosestElement(arr, n, k, x);
  cout << endl;
  return 0;
}
