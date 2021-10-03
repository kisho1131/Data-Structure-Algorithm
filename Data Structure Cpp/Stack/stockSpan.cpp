#include<bits/stdc++.h>
using namespace std;

vector<int> stockSpan(int arr[], int n){
  std::vector<int> v;
  stack<pair<int, int> >s;
  for(int i=0;i<n;i++){
    if(s.empty())
       v.push_back(-1);
    else if( s.size() > 0 && s.top().first > arr[i])
       v.push_back(s.top().second);
    else if(s.size() > 0 && s.top().first <= arr[i]){
      while(!s.empty() && s.top().first <= arr[i])
        s.pop();
      if(s.empty())
        v.push_back(-1);
      else
        v.push_back(s.top().second);
    }

    s.push(make_pair(arr[i], i));
  }

  return v;
}

int main(int argc, char const *argv[]) {

  int arr[] = {100, 80, 60, 70, 60, 75, 85, 120};
  int n = sizeof(arr) / sizeof(arr[0]);
  vector<int>v;
  v = stockSpan(arr, n);
  for(int i =0;i<n;i++){
    v[i] = i - v[i];
  }
  for(auto x:v){
    cout<<x<<" ";
  }
  return 0;
}
