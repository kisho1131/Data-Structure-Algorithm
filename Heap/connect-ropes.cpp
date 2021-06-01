/* optimal cost of the rope */
#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void ConnectRopes(int arr[], int n) {
  priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
  int cost = 0;
  while (pq.size() > 1) {
    int len1 = pq.top();
    pq.pop();
    int len2 = pq.top();
    pq.pop();
    cost = cost + len1 + len2;
    pq.push(len1 + len2);
  }
  cout << cost;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  ConnectRopes(arr, n);
  cout << endl;
  return 0;
}
