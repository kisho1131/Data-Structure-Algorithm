#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector <int> v1;
    heap <int> heap
    v1.push_back(21);
    v1.push_back(67);
    v1.push_back(56);
    v1.push_back(90);
    v1.push_back(55);
    v1.push_back(44);
    heap = make_heap(v1.begin(), v1.end());
    int k = 4;
    for(int i =0; i<k;i++){
        heap.pop_heap();
    }
    cout<<k<<" Largest Element in the Sequence is: "<<heap.front();
    return 0;
}
