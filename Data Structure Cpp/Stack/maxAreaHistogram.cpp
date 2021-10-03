#include<bits/stdc++.h>
using namespace std;

vector<int> LeftIndex(int arr[], int n){
  stack<pair<int, int> >s;
  vector<int>v;
  for(int i=0;i<n;i++){
    while(!s.empty() && s.top().first >= arr[i]){
      s.pop();
    }
    if(s.empty())
      v.push_back(-1);
    else
      v.push_back(s.top().second);
    s.push(make_pair(arr[i], i));
  }
  return v;
}

vector<int> RightIndex(int arr[], int n){
  stack<pair<int, int> >s;
  vector<int>v;
  for(int i=n-1; i>=0;i--){
    if(s.empty())
     v.push_back(n);
    else if(s.size() > 0 && s.top().first <= arr[i])
      v.push_back(s.top().second);
    else if(s.size() > 0 && s.top().first > arr[i]){
      while(s.size() > 0 && s.top().first > arr[i])
        s.pop();
      if(s.empty())
        v.push_back(n);
      else
        v.push_back(s.top().second);
    }
    s.push(make_pair(arr[i], i));
  }
  return v;
}

int main(int argc, char const *argv[]) {

  int arr[] ={2};
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<int> left = LeftIndex(arr, n);
  // for(int i=0;i<n;i++){
  //   left[i] = i - left[i];
  // }
  for(auto x: left)
     cout<<x<<" ";
  cout<<endl;
  vector<int> right = RightIndex(arr, n);
  reverse(right.begin(), right.end());
  // for(int i=0;i<n;i++){
  //   right[i] = right[i]-i;
  // }
  for(auto x: right)
    cout<<x<<" ";
  cout<<endl;
  int wid[n];
  for(int i=0; i<n;i++){
    wid[i] = right[i] - left[i] -1;
  }
  for(int i=0;i<n;i++){
    cout<<wid[i]<<" ";
  }
  int area[n];
  for(int i=0;i<n;i++){
    area[i] = arr[i] * wid[i];
  }
  cout<<endl;
  cout<<"Max Area = "<<*max_element(area, area+n);
  return 0;
}
