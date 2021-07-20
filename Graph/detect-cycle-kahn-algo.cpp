#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

bool DetectCycle(int V, vector<int> adj[]) {
  vector<int> inDegree(V, 0);
  queue<int> q;
  int count = 0;
  /* Found the inDegree of all the node in the Graph */
  for (int i = 0; i < V; i++)
    for (auto node : adj[i])
      inDegree[node]++;
  /* Push the Node with Zero inDegree */
  for (int i = 0; i < V; i++)
    if (inDegree[i] == 0)
      q.push(i);
  /* Perform the BFS Search */
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    count++;
    for (auto ele : adj[node]) {
      if (inDegree[ele] == 0)
        q.push(ele);
      inDegree[ele]--;
    }
  }
  if (count == V)
    return false;
  return true;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int V, E;
  cin >> V >> E;
  vector<int> adj[V];
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  if (DetectCycle(V, adj))
    cout << "Cycle";
  else
    cout << "Not Cycle";
  cout << endl;
  return 0;
}
