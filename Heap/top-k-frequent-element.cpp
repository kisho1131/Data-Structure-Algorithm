#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void TopKFrequent(int arr[], int n, int k) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }
  for (auto ele : mp) {
    pq.push({ele.second, ele.first});
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
  int arr[] = {1, 1, 1, 3, 2, 4, 1, 3};
  int k = 2;
  int n = sizeof(arr) / sizeof(arr[0]);
  TopKFrequent(arr, n, k);
  cout << endl;
  return 0;
}
