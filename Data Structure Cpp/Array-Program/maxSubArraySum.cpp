// Time Complexity :- O(n^3)
// Use of the three nested Loop

#include<bits/stdc++.h>
using namespace std;

void printMaxSum(int arr[], int n){
    int maxSum = 0;
    int currentSum =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            currentSum =0;
            for(int k=i; k<=j; k++){
                currentSum += arr[k];
            }
            if(currentSum>maxSum)
                maxSum = currentSum;
        }
    }
    cout<<"Maximum Sum of the subarray is: "<<maxSum;
}

int main(int argc, char const *argv[])
{
    int arr[] = {-4,1,3,-2,6,2,-8,-9,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxSum(arr, n);
    return 0;
}
