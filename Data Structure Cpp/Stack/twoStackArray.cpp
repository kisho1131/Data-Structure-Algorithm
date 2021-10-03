// Implemention of the two stack using the single Array
// The idea is to start start pusing the element for the left most corner
// for the stack-1 and start pushing from the right most corner for stack-2

#include<bits/stdc++.h>
using namespace std;

class Stack{
private:
    int *arr;
    int top1;
    int top2;
    int size;
public:
    Stack(int n){
        arr = new int[n];
        size = n;
        top1 = -1;
        top2 = size;
    }
    void push1(int x){
        if(top1<top2-1){
            top1++;
            arr[top1] = x;
        }
    }

    void push2(int x){
        if(top1<top2-1){
            top2--;
            arr[top2] = x;
        }
    }

    int pop1(){
        if(top1<0){
            cout<<"Underflow";
            exit(1);
        }
        int item = arr[top1];
        top1--;
        return item;
    }

    int pop2(){
        if(top2>size-1){
            cout<<"Underflow";
            exit(0);
        }
        int item = arr[top2];
        top2++;
        return item;
    }
};

int main(int argc, char const *argv[])
{
    // int item;
    Stack s(10);
    s.push1(20);
    s.push2(30);
    s.push1(40);
    s.push2(78);
    cout<<s.pop1();
    cout<<endl;
    cout<<s.pop2();
    return 0;
}
