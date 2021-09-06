/* Find the Minium swap to make the array sorted */

#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int MinimumSwap(vector<int> arr) {
  int n = arr.size();
  int minSwap = 0;
  pair<int, int> ap[n];
  for (int i = 0; i < n; i++) {
    ap[i].first = arr[i];
    ap[i].second = i;
  }
  sort(ap, ap + n);
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    int old_position = ap[i].second;
    // If the Element is in the right position || if the element is Visited then
    // Continue
    if (visited[i] == true or old_position == i)
      continue;

    // If the Element is Not Visited
    int cycle = 0;
    int node = i;
    while (!visited[node]) {
      visited[node] = true;
      int next_node = ap[node].second;
      node = next_node;
      cycle++;
    }
    minSwap += cycle - 1;
  }
  return minSwap;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  vector<int> arr = {5, 4, 3, 2, 1};
  cout << MinimumSwap(arr);
  cout << endl;
  return 0;
}
