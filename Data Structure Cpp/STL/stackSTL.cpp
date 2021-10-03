#include<iostream>
#include<stack>
using namespace std;

int main(int argc, char const *argv[]) {
  stack<int>s1;
  stack<int>s2;
  for(int i=1;i<8;i++){
    s1.push(i*10);
  }
  cout<<endl;
  for(int i=1;i<20;i++){
    s2.push(i*20);
  }
  cout<<endl;
  cout<<"Top of s1: "<<s1.top()<<endl;
  cout<<"Top of s2: "<<s2.top()<<endl;
  cout<<"size of s1: "<<s1.size()<<endl;
  cout<<"size of s2: "<<s2.size()<<endl;
  cout<<endl;
  cout<<"After Swapping: "<<endl;

  s1.swap(s2);
  cout<<endl;
  cout<<"Top of s1: "<<s1.top()<<endl;
  cout<<"Top of s2: "<<s2.top()<<endl;
  cout<<"size of s1: "<<s1.size()<<endl;
  cout<<"size of s2: "<<s2.size();


  return 0;
}
