#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[], int u, int v){
  adj[u].push_back(v);
}
int MotherEdge(vector<int>adj[], int v){
  bool vis[v+1];
  memset(vis, false, sizeof(vis));
  queue<int>q;
  for(int i=1;i<v;i++){
    q.push(i)
    vis[i] = true;
    while(!q.empty()){
      int u = q.front();
      q.pop();
      for(auto v : adj[u]){
        if(vi[*v] == false){

        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {


  return 0;
}
