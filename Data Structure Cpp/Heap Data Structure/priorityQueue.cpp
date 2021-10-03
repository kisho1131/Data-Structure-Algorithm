#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int, vector<int>, greater<int> > pq;  // min-heap priority queue
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        pq.push(num);
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";7
        pq.pop();
    }
    return 0;
}
