/*
Question
1. You are given an array of length n containing numbers from 1 to n.
2. One number is present twice in array and one is missing.
3. You have to find these two numbers.
*/

#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]) {
  vector<int>arr;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    int num;
    cin>>num;
    arr.push_back(num);
  }
  int xxory = 0;
  for(auto val:arr){
    xxory = xxory ^ val;
  }
  for(int i=1;i<=n;i++){
    xxory^=i;
  }
  int rmsb = xxory & -xxory;
  int x =0;
  int y =0;
  for(auto val:arr){
    if((val & rmsb) == 0){
      x = x^val;
    }
    else{
      y = y^val;
    }
  }
  for(auto val:arr){
    if(val==x){
      cout<<"Missing Number -> "<<y<<endl;
      cout<<"Repeating Number -> "<<x;
      break;
    }
    else{
      cout<<"Missing Number -> "<<x<<endl;
      cout<<"Repeating Number -> "<<y;
      break;
    }
  }
  // cout<<x<<"->"<<y;
  return 0;
}
