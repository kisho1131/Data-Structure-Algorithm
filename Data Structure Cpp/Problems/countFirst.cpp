#include <iostream>
using namespace std;

int binarySearch(int arr[],int start, int end, int value){
    int result = -1;
    if(start > end)
        return result;
    int mid = (start+end)/2;
    if(arr[mid] == value){
        result = mid;
        end = mid -1;
    }
    else if (value < arr[mid])
        binarySearch(arr, 0 , mid-1, value);
    else
        binarySearch(arr, mid+1, end, value);
}

int main(int argc, char const *argv[])
{
    int arr[] = {12,12,12,77,89,90,990};
    int len = sizeof(arr)/sizeof(arr[0]);
    int value = 12;
    int index = binarySearch(arr, 0, len-1, value);
    if (index == -1)
        cout<<"Element Not found !!!!";
    else
        cout<<"Element found at index:"<<index +1;
    cout<<endl;
     return 0;
    }
