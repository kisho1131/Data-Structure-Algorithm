#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char const *argv[]) {

  queue<int>q1;
  queue<int>q2;
  for(int i=1;i<5;i++){
    q1.push(i*10);
  }
  cout<<q1.size()<<endl;
  cout<<q1.front()<<endl;
  cout<<q1.back()<<endl;
  q1.pop();
  cout<<q1.front();
  return 0;
}
