#include<iostream>
#include<map>
#include<set>
#include<iterator>
using namespace std;

int main(int argc, char const *argv[])
{
  set<int>s;
  int arr[] = {12,34,45,12,45,66,66,77};
  int n = sizeof(arr) / sizeof(arr[0]);
  for(int i=0;i<n;i++){
    s.insert(arr[i]);
  }
  cout<<" Size of set is: ";
  cout<<s.size();
  return 0;
}
