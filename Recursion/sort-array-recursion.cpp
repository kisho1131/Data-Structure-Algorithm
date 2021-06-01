#include<iostream>
using namespace std;

void insert_data(vector<int>&v, int temp){
  if(v.size()==0 || v[v.size()-1] <= temp){
    v.push_back(temp);
    return;
  }
  int val = v[v.size()-1];
  v.pop_back();
  insert_data(v, temp);
  v.push_back(val);
}

void sort_array(vector<int>&v){
  if(v.size()==1)
  return ;
  int temp = v[v.size()-1];
  v.pop_back();
  sort(v);
  insert_data(v, temp);
}

int main(int argc, char const *argv[]) {
  vector<int>v;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    v.push_back(num);
  }
  sort_array(v);
  for(auto x: v){
    cout<<x<<"->";
  }
  return 0;
}
