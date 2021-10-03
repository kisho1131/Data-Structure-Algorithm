// Find the Nearest Smallest to the Left

#include<bits/stdc++.h>
using namespace std;

vector<int> NearestSmallestLeft(int arr[], int n){
  vector<int>res;
  stack<int>s;
  for(int i=0;i<n;i++){
    while(!s.empty() && s.top() >= arr[i])
       s.pop();
    if(!s.empty())
      res.push_back(s.top());
    else
      res.push_back(-1);
    s.push(arr[i]);
  }
  return res;
}

int main(int argc, char const *argv[]) {

  int arr[] = {2, 4, 8, 7, 7, 9, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  vector<int>res;
  res = NearestSmallestLeft(arr, n);
  for(auto x:res){
    cout<<x<<" ";
  }
  return 0;
}
