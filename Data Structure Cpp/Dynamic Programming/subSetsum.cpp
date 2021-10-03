//  Subset Sum Problem Using Resursion //

#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum){
  if(sum!=0 && n==0)
     return false;
  if(sum == 0)
     return true;
  if (arr[n - 1] > sum)
      return isSubsetSum(arr, n - 1, sum);
  return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main(int argc, char const *argv[]) {
  int arr[] = { 3, 34, 4, 12, 5, 2 };
  int n = sizeof(arr)/ sizeof(arr[0]);
  int sum = 9;
  if(isSubsetSum(arr, n, sum)){
    cout<<"True";
    }
  else
    cout<<"Flase" ;
  // cout<<ans;
  return 0;
}
