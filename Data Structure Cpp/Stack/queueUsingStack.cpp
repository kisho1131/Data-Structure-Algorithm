#include<bits/stdc++.h>
using namespace std;
struct Queue{
    stack<int> s1, s2;
    // Enqueue an element
    void enQueue(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    // Dequeue an element
    int deQueue(){
        if(s1.empty()){
            cout<<"Queue is empty: ";
            exit(0);
        }
        int x = s1.top();
        s1.pop();
        return x;
    }
};

int main(int argc, char const *argv[])
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    cout<<q.deQueue();
    cout<<endl;
    cout<<q.deQueue();
    cout<<endl;
    cout<<q.deQueue();
    cout<<endl;
    cout<<q.deQueue();
    cout<<endl;
    return 0;
}
