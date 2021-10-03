#include<bits/stdc++.h>
using namespace std;

int FindTriplet(int arr[], int n){
  int count = 0;
  for(int i=0;i<n;i++){
    int val = arr[i];
    for(int k= i+1;k<n;k++) {
      val = val^arr[k];
      if(val == 0)
        count += k-i;
    }
  }
  return count;
}

int main(int argc, char const *argv[]) {
  int arr[] = {1,2,3};
  int n = sizeof(arr)/sizeof(int);
  int count = FindTriplet(arr, n);
  cout<<count;
  return 0;
}
