#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[]) {

  int arr[] = {1,3,0,9,6,4,2};
  int n= sizeof(arr)/sizeof(arr[0]);
  int key =9;
  auto it = find(arr, arr+n, key); // Linear search STL
  cout<<endl;
  cout<<it - arr;
  int arr2[] = {1,2,3,4,4,4,4,4,5,6,7,8,9};
  int n1 = sizeof(arr2)/sizeof(arr2[0]);
  bool pos = binary_search(arr2, arr2+n, 6);
  if(pos){
    cout<<"found data";
  }
  else{
    cout<<" Absent!!";
  }
  
  cout<<endl;
  auto lb = lower_bound(arr2, arr2+n1, 4);
  cout<<endl;
  cout<<"Lower Bound: "<<lb-arr2;
  auto ub = upper_bound(arr2, arr2+n1, 4);
  cout<<endl;
  cout<<"Upper Bound: "<<ub-arr2;
  cout<<endl;
  cout<<"Freq of 4 is: "<<(ub-lb);
  cout<<endl;
  cout<<count(arr2,arr2+n1, 4);

  sort(arr, arr+n);
  cout<<endl;
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
