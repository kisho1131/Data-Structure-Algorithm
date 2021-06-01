#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
class Kstack {
  int *arr;
  int *next;
  int *top;
  int n, k;
  int free;

public:
  Kstack(int k, int n);
  bool isFull() { return free == -1; }
  void push(int item, int sn);
  int pop(int sn);
  bool isEmpty(int sn) { return top[sn] == -1; }
};

Kstack ::Kstack(int k1, int n1) {
  k = k1, n = n1;
  arr = new int[n];
  top = new int[k];
  next = new int[n];
  free = 0;
  for (int i = 0; i < n - 1; i++)
    next[i] = i + 1;
  next[n - 1] = -1;
  for (int i = 0; i < k; i++)
    top[i] = -1;
}

void Kstack ::push(int item, int sn) {
  if (isFull()) {
    cout << "Stack OverFlow" << endl;
    return;
  }
  int idx = free;
  free = next[idx];
  next[idx] = top[sn];
  top[sn] = idx;
  arr[idx] = item;
}

int Kstack ::pop(int sn) {
  if (isEmpty(sn)) {
    cout << "Stack UnderFlow";
    return INT_MAX;
  }
  int idx = top[sn];
  top[sn] = next[idx];
  next[idx] = free;
  free = idx;
  return arr[idx];
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int k = 3, n = 10;
  Kstack ks(k, n);

  // Let us put some items in stack number 2
  ks.push(15, 2);
  ks.push(45, 2);

  // Let us put some items in stack number 1
  ks.push(17, 1);
  ks.push(49, 1);
  ks.push(39, 1);

  // Let us put some items in stack number 0
  ks.push(11, 0);
  ks.push(9, 0);
  ks.push(7, 0);

  cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
  cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
  cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
  cout << endl;
  return 0;
}
