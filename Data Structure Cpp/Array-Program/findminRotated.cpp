// program to find the minimun element in the rotated array

#include<bits/stdc++.h>
using namespace std;

int findMin(int arr[], int low, int high)
{
    while(low < high)
    {
        int mid = low + (high - low)/2;
        cout<<mid<<endl;
        if (arr[mid] == arr[high])
            high--;
        else if(arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return arr[high];
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = findMin(arr,0, n-1);
    cout<<"Minimum element: "<<result;
    return 0;
}
