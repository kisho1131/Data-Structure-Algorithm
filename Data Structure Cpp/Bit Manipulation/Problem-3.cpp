/*
                                   Josephus Special
Question
1. You are given an integer N which represents the total number of soldiers standing in a circle
     having position marked from 1 to N.
2. A cruel king wants to execute them but in a different way.
3. He starts executing soldiers from 1st position and proceeds around the circle in clockwise
     direction.
4. In each step, every second soldier is executed.
5. The elimination proceeds around the circle (which is becoming smaller and smaller as the
     executed soldiers are removed), until only the last soldier remains, who is given freedom.
6. You have to find the position of that lucky soldier.
*/

#include<bits/stdc++.h>
using namespace std;
int power2(int n){
  int i=1;
  while(i*2 <= n){
    i = i*2;
  }
  return i;
}

int JoshespusCircle(int n){
  int hp2 = power2(n);
  int l = n - hp2;
  int ans = 2*l+1;
  return ans;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int ans = JoshespusCircle(n);
  cout<<"Ans = "<<ans;
  return 0;
}
