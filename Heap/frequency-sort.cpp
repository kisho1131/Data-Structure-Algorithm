#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void FrequencySort(int arr[], int n) {
  unordered_map<int, int> mp;
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }
  for (auto ele : mp) {
    pq.push({ele.second, ele.first});
  }
  while (!pq.empty()) {
    int item = pq.top().second;
    int freq = pq.top().first;
    for (int i = 0; i < freq; i++) {
      cout << item << " ";
    }
    pq.pop();
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 3, 1, 5, 3, 2, 6, 3, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  FrequencySort(arr, n);
  cout << endl;
  return 0;
}
