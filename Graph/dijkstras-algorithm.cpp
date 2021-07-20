#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void Dijkstras(int V, int source, vector<pair<int, int>> adj[]) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> disTo(V, INT_MAX);
  pq.push({0, source});
  while (!pq.empty()) {
    int dist = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    for (auto it : adj[node]) {
      int nextDist = it.first;
      int nextNode = it.second;
      if (disTo[nextNode] > dist + nextDist) {
        disTo[nextNode] = dist + nextDist;
        pq.push({nextDist, nextNode});
      }
    }
  }
  for (int i = 1; i < disTo.size(); i++) {
    cout << "Distance from " << source << " --> " << i << " = " << disTo[i]
         << endl;
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {

  cout << endl;
  return 0;
}
