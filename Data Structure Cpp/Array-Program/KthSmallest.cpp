// Find the kth Smallest and the largest element in the array

#include<bits/stdc++.h>
using namespace std;


int kthSmallest(int arr[], int n, int k){
    set <int> s;
    for(int i=0;i<n;i++)
        s.insert(arr[i]);
    auto it = s.begin();
    for(int j=0; j<k; j++)
        it++;
    return *it;
}

int main(int argc, char const *argv[])
{
    int arr[] = { 12, 3, 5, 7, 3, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is "
         << kthSmallest(arr, n, k);
    return 0;
}
