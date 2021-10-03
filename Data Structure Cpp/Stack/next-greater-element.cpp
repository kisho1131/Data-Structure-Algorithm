#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(int arr[], int n){
  vector<int>v;
  stack<int>s;
  for(int i= n-1;i>=0;i--){
    if(s.size()==0)
       v.push_back(-1);
    else if(s.size()>0 && s.top() <= arr[i]){
       v.push_back(s.top());
    }
    else if(s.size()>0 && s.top() > arr[i]){
      while(s.empty() || s.top() > arr[i]){
        s.pop();
      }
      if(s.size()==0)
        v.push_back(-1);
      else
        v.push_back(s.top());
    }
    s.push(arr[i]);
  }
  return v;
}

int main(int argc, char const *argv[]) {
  int arr[] = {11, 13, 21, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  vector<int>v;
  v = nextGreater(arr, n);
  reverse(v.begin(), v.end());
  for(int i =0;i<v.size();i++){
    cout<<v[i]<<"--> ";
  }
  return 0;
}
