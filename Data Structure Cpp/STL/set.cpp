/*

begin() – Returns an iterator to the first element in the set.
end() – Returns an iterator to the theoretical element that follows last element in the set.
size() – Returns the number of elements in the set.
insert(val) – Inserts a new element val in the Set.
find(val) - Returns an iterator pointing to the element val in the set if it is present.
empty() – Returns whether the set is empty.

*/

#include<iostream>
#include<set>
using namespace std;


int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 67, 20, 20, 67, 67, 34, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    set<int>s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    cout<<s.size();
    return 0;
}
