#include<bits/stdc++.h>
using namespace std;


bool duplicateBracket(string exp){
  stack<char>s;
  for(int i=0;i<exp.length();i++){
    if(exp[i] == ')'){
      if(s.top() == '(')
        return true;
      else{
        while(s.top() !='(')
          s.pop();
        s.pop();
      }
    }
    else
     s.push(exp[i]);
  }
  return false;
}

int main(int argc, char const *argv[]) {

  string exp1 = "(a+b) + (c+d)";
  string exp2 = "((a+b)) + (c+d) + ((w+r))";
  if(duplicateBracket(exp1))
    cout<<"True";
  else
    cout<<"False" ;
  cout<<endl;
  if(duplicateBracket(exp2))
    cout<<"True";
  else
    cout<<"False";
  return 0;
}
