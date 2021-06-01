/* Sort a nearly sorted (or K sorted) array */
#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

void KSortedArray(int arr[], int k, int n) {
  priority_queue<int, vector<int>, greater<int>> pq(arr, arr + k + 1);
  int index = 0;
  for (int i = k + 1; i < n; i++) {
    arr[index++] = pq.top();
    pq.pop();
    pq.push(arr[i]);
  }
  while (!pq.empty()) {
    arr[index++] = pq.top();
    pq.pop();
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int k = 3;
  int arr[] = {2, 6, 3, 12, 56, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  KSortedArray(arr, k, n);
  printArray(arr, n);
  return 0;
}
