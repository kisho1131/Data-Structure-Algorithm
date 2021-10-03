#include<bits/stdc++.h>
using namespace std;
struct Stack
{
    queue<int> q1;
    queue<int> q2;
    void push(int x){
        if(q1.empty())
            q1.push(x);
        else{
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
    }

    int pop(){
        if(q1.empty()){
            cout<<"No element";
            exit(0);
        }

        int x = q1.front();
        q1.pop();
        return x;
    }
};

int main(int argc, char const *argv[])
{
    Stack S;
    S.push(10);
    S.push(20);
    S.push(30);
    S.push(40);
    S.push(50);
    int item = S.pop();
    cout<<item;
    return 0;
}
