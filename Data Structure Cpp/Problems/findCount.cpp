#include <iostream>
using namespace std;


int findFirst(int arr[], int start, int end, int x){
    int mid = (start+end)/2;
    int result = -1;
    if (start > end)
        return result;
    if (x == arr[mid]){
        result = mid;
        end = mid-1;
    }
    else if(x < arr[mid])
        findFirst(arr, start, mid-1, x);
    else
        findFirst(arr, mid+1, end, x);
}

int findLast(int arr[], int start, int end, int x){
    int mid = (start+end)/2;
    int result = -1;
    if (start > end)
        return result;
    if (x == arr[mid]){
        result = mid;
        start = mid+1;
    }
    else if(x < arr[mid])
        findLast(arr, start, mid-1, x);
    else
        findLast(arr, mid+1, end, x);
}


int main(int argc, char const *argv[])
{
    int arr[] = {1,1,1,2,2,3,3,4,4,4,4,4,4,4,5,6,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    int num = 4;
    int first = findFirst(arr, 0, len-1,num);
    int last = findLast(arr, 0 , len-1, num);
    cout<<first<<endl;
    cout<<last<<endl;
    int count = last - first;
    cout<<"Total Count of "<<num<<" is:"<<count<<endl;
    return 0;
}
