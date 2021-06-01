#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int minEle = -1;
/*===========Your Code Here=============*/
void popMin() {
  if (s.size() == 0)
    return;
  else if (s.top() < minEle) {
    minEle = 2 * minEle - s.top(); // Moving Back to the Previous Element
    s.pop();
  } else
    s.pop();
}
void pushMin(int x) {
  if (s.size() == 0) {
    s.push(x);
    minEle = x;
  } else if (x < minEle) {
    s.push(2 * x - minEle);
    minEle = x;
  } else {
    s.push(x);
  }
}
int topMin() {
  if (s.size() == 0)
    return -1;
  else if (s.top() < minEle) {
    return minEle;
  } else
    return s.top();
}
int getMin() { return minEle; }

/*============Main()====================*/

int main(int argc, char const *argv[]) {
  pushMin(5);
  pushMin(3);
  pushMin(9);
  pushMin(2);
  pushMin(1);
  cout << topMin();
  popMin();
  cout << endl;
  cout << getMin();
  cout << endl;
  return 0;
}
