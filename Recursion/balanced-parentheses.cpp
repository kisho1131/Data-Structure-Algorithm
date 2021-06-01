#include<bits/stdc++.h>
using namespace std;

void helper(int o, int c, string op, vector<string>&res){
  if(c ==0 && o==0){
    res.push_back(op);
    return;
  }
  if(o!=0){
    string op1 = op;
    op1.push_back('(');
    helper(o-1, c, op1, res);
    if(c > o){
      string op2 = op;
      op2.push_back(')');
      helper(o, c-1, op2, res);
   }
 }
}
vector<string> solve(int n){
  vector<string>res;
  int o, c = n;
  string op = "";
  helper(o, c, op, res);
  return res;
}
int main(int argc, char const *argv[]) {

  int n;
  cin>>n;
  vector<string>res = solve(n);
  for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
  }
  return 0;
}
