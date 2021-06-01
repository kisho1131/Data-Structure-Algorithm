#include<bits/stdc++.h>
using namespace std;
void helper_solve(string ip, string op, vector<string>&res){
  if(ip.length()==0){
    res.push_back(op);
    return;
  }
  if(isalpha(ip[0])){
    string op1 = op;
    string op2 = op;
    op1.push_back(tolower(ip[0]));
    op2.push_back(toupper(ip[0]));
    ip.erase(ip.begin()+0);
    helper_solve(ip, op1, res);
    helper_solve(ip, op2, res);
  }
  else{
    string op1 = op;
    op1.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    helper_solve(ip, op1, res);
  }
}
vector<string> solve(string ip, string op){
  vector<string>res;
  helper_solve(ip, op, res);
  return res;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif

  string ip;
  string op = "";
  cin>>ip;
  vector<string> res = solve(ip, op);
  for(int i=0;i<res.size();i++){
    cout<<res[i]<<" "<<endl;
  }
  return 0;
}
