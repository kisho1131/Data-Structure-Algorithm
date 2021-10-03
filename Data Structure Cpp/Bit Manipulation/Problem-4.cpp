/*
                         All Repeating Except Two
Question
1. You are given an array of numbers.
2. You have to find 2 non-repeating numbers in an array.
3. All repeating numbers are repeating even number of times.
*/
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
 // int arr[] = {36,50,24,56,36,24,42,50};
  vector<int>arr;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
      int num;
      cin>>num;
      arr.push_back(num);
  }
  int xxory = 0;
  for(auto val:arr){
    xxory = xxory ^ val;
  }
  int rmsb = xxory & -xxory;
  int x =0;
  int y =0;
  for(auto val:arr){
    if((val & rmsb) == 0){
      x = x ^ val;
    }
    else{
      y = y ^ val;
    }
  }
  if(x < y){
  cout<<x<<endl;
  cout<<y;
  }
  else{
  cout<<y<<endl;
  cout<<x;
  }
  return 0;
}
