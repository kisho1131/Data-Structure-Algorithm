#include<bits/stdc++.h>
using namespace std;

void delete_middle(stack<int>&s, int k){
  if(s.size()==0)
    return;
  if(k == 1){
    s.pop();
    return;
  }
  int temp = s.top();
  s.pop();
  delete_middle(s, k-1);
  s.push(temp);
}


int main(int argc, char const *argv[]) {

  stack<int>s;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    s.push(num);
  }
  cout<<s.size();
  cout<<endl;
  int k = (s.size()/2) +1;
  delete_middle(s,k);
  cout<<s.size();
  cout<<endl;
  int count = 0;
  for(int i=0;i<n-1; i++){
    cout<<s.top()<<" ";
    s.pop();
    count++;
  }
  cout<<endl;
  cout<<count;
  return 0;
}
