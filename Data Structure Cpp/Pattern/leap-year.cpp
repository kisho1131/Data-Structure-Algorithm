#include<iostream>
using namespace std;

bool findLeap(int y){
  if(y%400 == 0)
    return true;
  if(y%100 == 0)
    return false;
  if(y%4 == 0)
    return true;
  return false;
}
int main(int argc, char const *argv[]) {

  int year;
  cin>>year;
  if(findLeap(year))
    cout<<"Leap";
  else
    cout<<"Not Leap";
  return 0;
}
