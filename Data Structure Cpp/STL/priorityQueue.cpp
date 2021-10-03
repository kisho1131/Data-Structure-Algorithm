#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char const *argv[]) {


  priority_queue <int> gquiz; // Create a max heap :)
  priority_queue<int, vector<int>, greater<int> > pq; // Create a min Heap

  gquiz.push(10);
  gquiz.push(12); // O(logn)
  cout<<gquiz.top();
  gquiz.push(10);
  gquiz.push(30);
  gquiz.push(20);
  gquiz.push(5);
  gquiz.push(1);
  cout<<endl;
  while(!gquiz.empty()){
    cout<<gquiz.top()<<"  ";
    gquiz.pop();
  }
  return 0;
}
