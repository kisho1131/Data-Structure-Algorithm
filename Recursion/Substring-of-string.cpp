#include<bits/stdc++.h>
using namespace std;


void find_substring(string ip, string op){
  if(ip.length() == 0){
    cout<<op<<endl;
    return;
  }
  string op1 = op;
  string op2 = op;
  op2.push_back(ip[0]);
  ip.erase(ip.begin()+0);
  find_substring(ip, op1);
  find_substring(ip, op2);
}

int main(int argc, char const *argv[]) {
  string ip;
  string op = "";
  cin>>ip;
  //et<string>res;
  find_substring(ip, op);
  // cout<<res;
  // for(auto itr =res.begin(); itr!=res.end();itr++){
  //   cout<<*itr;
  // }
  return 0;
}
