// program to count the pre for the array
#include<bits/stdc++.h>
using namespace std;

void countPreSum(int arr[], int n){
    int *preSum = new int[n+1]; // Use the dynamic array alllocation if the size of the array is not constant
    preSum[0] = 0;
    for(int i = 1; i<n; i++){
        preSum[i] = preSum[i-1] + arr[i-1];
    }
    for(int j = 0; j<n;j++){
        cout<<preSum[j]<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    countPreSum(arr, n);
    return 0;
}
