#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int>s;
    void enQueue(int x){
        s.push(x);
    }
    int deQueue(){
        if(s.empty()){
            cout<<"Queue is empty:(";
            exit(0);
        }
        int x = s.top();
        s.pop();
        if(s.empty())
            return x;
        int item = deQueue();
        s.push(x);
        return item;
    }
    void print(){
        while(!s.empty()){
            cout<<s.top();
            cout<<endl;
            s.pop();
        }
    }
};
int main(int argc, char const *argv[])
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
   // q.print();
    cout<<q.deQueue();
    cout<<endl;
    return 0;
}
