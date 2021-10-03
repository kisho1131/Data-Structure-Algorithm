#include<iostream>
#include<queue>
using namespace std;


int main(int argc, char const *argv[]) {
  std::vector<int> v;
  priority_queue<int, vector<int>, greater<int> >pq;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    v.push_back(num);
  }
  int k;
  cin>>k;
  for(int j=0;j<k;j++){
    pq.push(v[j]);
  }
  for(int l = k; l<n;l++){
    if(v[l] > pq.top()){
      pq.pop();
      pq.push(v[l]);
    }
  }

  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }
  return 0;
}
