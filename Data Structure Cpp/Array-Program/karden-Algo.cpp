// Find the maximum subarray sum in O(n) time

#include<bits/stdc++.h>
using namespace std;

int kardenAlgo(int arr[], int n){
    int sum =arr[0], best = INT_MIN;
    for(int i=0;i<n;i++){
        sum = max(arr[i], sum + arr[i]);
        best = max(sum, best);
    }
    return best;
}

int main(int argc, char const *argv[])
{
    int arr[] = {-4,-2,-2,-8,-9,-4,- 6,-2,-6,-7};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int maxSum = kardenAlgo(arr, n);
    cout<<maxSum;
    return 0;
}
