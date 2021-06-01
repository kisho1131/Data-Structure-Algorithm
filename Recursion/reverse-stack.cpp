#include<bits/stdc++.h>
using namespace std;


void reverse_stack(stack<int>&s){
  if(s.size()==0)
  return;
  int temp = s.top();
  s.pop();
  reverse_stack(s);
  s.push(temp);

}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  stack<int>s;
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    s.push(num);
  }
  reverse_stack(s);
  for(int i=0;i<n;i++){
    cout<<s.top()<<" ";
    s.pop();
  }
  return 0;
}
