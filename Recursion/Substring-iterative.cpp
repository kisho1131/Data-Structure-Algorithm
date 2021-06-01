#include<bits/stdc++.h>
using namespace std;

set<string> find_substring(string s){
  set<string>res;
  for(int i=0;i<=s.length();i++){
    for(int j = 1; j<=s.length()-i;j++){
      res.insert(s.substr(i, j));
    }
  }
  return res;
}

int main(int argc, char const *argv[]) {
  set<string>res;
  string s;
  cin>>s;
  res = find_substring(s);
  for(auto itr = res.begin(); itr!=res.end(); itr++){
    cout<<*itr<<endl;
  }
  return 0;
}
