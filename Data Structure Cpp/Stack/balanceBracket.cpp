#include<bits/stdc++.h>
using namespace std;

bool arePair(char opening, char closing){
  if(opening == '(' && closing == ')') return true;
  else if(opening == '{' && closing == '}') return true;
  else if(opening == '[' && closing == ']') return true;
  return false;
}

bool isBalanced(string exp){
  stack<char>s;
  for(int i=0;i<exp.length();i++){
    if(exp[i] == '(' || exp[i]== '[' || exp[i] == '{')
        s.push(exp[i]);
    else if(exp[i] == ')' || exp[i]== ']' || exp[i] == '}'){
      if(s.empty() || !arePair(s.top(), exp[i]))
         return false;
      else
        s.pop();
    }
  }
  return s.empty() ? true:false;
}


int main(int argc, char const *argv[]) {

  string expression;
  cout<<"Enter an expression:  ";
  cin>>expression;
  if(isBalanced(expression))
      cout<<"Balanced\n";
  else
      cout<<"Not Balanced\n";
  return 0;
}
