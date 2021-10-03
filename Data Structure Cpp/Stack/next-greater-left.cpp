#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterLeft(int arr[], int n){
  vector<int>v;
  stack<int>s;
  for(int i=0;i<n;i++){
    if(s.empty())
       v.push_back(-1);
    else if(s.size()>0 && arr[i] > s.top()){
      while(s.size() > 0 && s.top() < arr[i])
         s.pop();
      if(s.empty())
        v.push_back(-1);
      else
        v.push_back(s.top());
    }
    else if(s.size() > 0 && s.top() > arr[i])
      v.push_back(s.top());
    s.push(arr[i]);
  }
  return v;
}

int main(int argc, char const *argv[]) {

  int arr[] ={ 1, 3, 4, 2};
  int n= sizeof(arr) / sizeof(arr[0]);
  vector<int>v;
  v = nextGreaterLeft(arr, n);
  for(auto x: v){
    cout<<x<<"-->";
  }
  return 0;
}
