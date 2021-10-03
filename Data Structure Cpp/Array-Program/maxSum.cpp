// Find the maximum subarray sum for the given array
// Time Complexity O(n^2)
// Space Complexity O(1)

#include<bits/stdc++.h>
using namespace std;

int maxSumArray(int arr[], int n){
    int best=0;
    for(int a=0; a<n;a++){
        int sum =0;
        for(int b=a; b<n;b++){
            sum += arr[b];
            best = max(best, sum);
        }
    }
    return best;
}
int main(int argc, char const *argv[])
{
    int arr[] = {-4,1,3,-2,6,2,-8,-9,4};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int maxSum = maxSumArray(arr, n);
    cout<<maxSum;
    return 0;
}
