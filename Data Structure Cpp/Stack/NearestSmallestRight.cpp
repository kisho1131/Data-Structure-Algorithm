#include<bits/stdc++.h>
using namespace std;

vector<int>NearestSmallestRight(int arr[], int n){
  stack<int>s;
  vector<int>v;
  reverse(arr, arr+n);
  for(int i=0;i<n;i++){
    while(!s.empty() && s.top() >= arr[i])
      s.pop();
    if(!s.empty())
      v.push_back(s.top());
    else
      v.push_back(-1);
    s.push(arr[i]);
  }
  reverse(v.begin(), v.end());
  return v;
}


int main(int argc, char const *argv[]) {

  int arr[] = {2, 4, 8, 1, 7, 9, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  vector<int>res;
  res = NearestSmallestRight(arr, n);
  for(auto x:res){
    cout<<x<<" ";
  }
  return 0;
}
