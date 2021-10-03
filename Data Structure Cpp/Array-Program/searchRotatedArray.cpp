#include<iostream>
using namespace std;

int circularsortedArray(int arr[], int n, int x){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == x) // when the element is found
            return mid;
        if(arr[mid] <= arr[high]){ // case:2 right half is sorted
            if(x > arr[mid] && x<= arr[high])
                low = mid+1; // go searching in the right sorted half
            else
                high = mid - 1;
        }
        else{
            if(arr[low] <= x && x < arr[mid])
                high = mid-1;
            else
                low = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num = 12;
    int result = circularsortedArray(arr, n, num);
    if(result == -1)
        cout<<"Element not found ";
    else
        cout<<"Element found at index: "<<result;
    return 0;
}
