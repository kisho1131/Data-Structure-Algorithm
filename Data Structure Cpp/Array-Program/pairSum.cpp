// Find the pair of element in the array with sum = k
// Using the two Pointer Method
// Time Complexity O(n)

#include<bits/stdc++.h>
using namespace std;

void pairSum(int arr[], int n, int k){
    int st = 0;
    int ed = n-1;
    while(st<ed){
        if(arr[st] + arr[ed] < k)
            st++;
        else if(arr[st] + arr[ed] > k)
            ed--;
        else{
            cout<<arr[st]<<" and " <<arr[ed]<<endl;
            st++;
            ed--;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10;
    pairSum(arr, n, k);
    return 0;
}
