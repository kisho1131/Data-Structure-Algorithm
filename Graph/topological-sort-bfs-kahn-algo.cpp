#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
vector<int> KahnAlgorithm(int V, vector<int> adj[]) {
  queue<int> q;
  vector<int> ans;
  vector<int> inDegree(V, 0);
  /* Calculating the InDegree */
  for (int i = 0; i < V; i++)
    for (auto it : adj[i])
      inDegree[it]++;
  /* Push the node into the queue if indegree is Zero */
  for (int i = 0; i < V; i++)
    if (inDegree[i] == 0)
      q.push(i);
  /* Doing the BFS Traversal & Reducing the Indegree */
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (auto it : adj[node]) {
      inDegree[it]--;
      if (inDegree[it] == 0)
        q.push(it);
    }
  }
  return ans;
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
  vector<int> ans = KahnAlgorithm(V, adj);
  for (auto ele : ans)
    cout << ele << " ";
  cout << endl;
  return 0;
}
