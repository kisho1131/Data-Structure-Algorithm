#include<bits/stdc++.h>
using namespace std;

void NearestSmallerLeft(int arr[], int n, int res[]){
  stack<pair<int, int> >s;
  for(int i=0;i<n;i++){
    while(!s.empty() && s.top().first >= arr[i])
       s.pop();
    if(!s.empty())
        res[i] = s.top().second;
    else
       res[i] = -1;
    s.push(make_pair(arr[i], i));
  }
}

int main(int argc, char const *argv[]) {

  int arr[] = {2, 4, 8, 7, 7, 9, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int ls[n+1];
  int rs[n+1];
  NearestSmallerLeft(arr, n, ls);
  for(int i=0;i<n;i++)
    cout<<ls[i]<<" ";
  cout<<endl;
  reverse(arr, arr+n);
  NearestSmallerLeft(arr, n, rs);
  //reverse(rs, rs+n);
  cout<<"Nesrest Smaller to Right: "<<endl;
  for(int i=0;i<n;i++){
    cout<<rs[i]<<" ";
  }
  return 0;
}
