#include<bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n){
    int *cSum = new int [n+1];
    cSum[0] = arr[0];
    for(int i=1; i<n;i++){
        cSum[i] = cSum[i-1] + arr[i];
    }
    int maxSum = 0;
    int current = 0;
    for(int i=0;i<n;i++){
         current = 0;
        for(int j=i;j<n;j++){
            current = cSum[j] - cSum[i-1];
        }
        if(current > maxSum)
            maxSum = current;
    }
    return maxSum;
}

int main(int argc, char const *argv[])
{
    int arr[] = {-4,1,3,-2,6,2,-8,-9,4};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int maxSum = subArraySum(arr, n);
    cout<<maxSum;
    return 0;
}
