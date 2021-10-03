#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int>v1;
    for(int i=0;i<10;i++)
        v1.push_back(i*i);
    vector<int>::iterator ptr; // iterator of type vector
    for(ptr = v1.begin(); ptr!=v1.end();ptr++)
        cout<<*ptr<<"->";\
    cout<<endl;
    cout<<v1.front();
    cout<<endl;
    cout<<v1.back();
    cout<<endl;
    for(auto x:v1){
      cout<<x<<",";
    }
    cout<<endl;
    cout<<v1.size()<<endl;
    cout<<"Capacity:"<<v1.capacity()<<endl;
    cout<<"Max Size:"<<v1.max_size()<<endl;
    cout<<endl;
    vector<char> v = {'s','k','d','d'};
    for(auto x:v){
      cout<<x<<" ";
    }

    v1.insert(v1.begin() + 3, 200);
    cout<<endl;
    cout<<"Size= "<<v1.size()<<endl;
    cout<<"Front= "<<v1.front()<<endl;
    cout<<"Back= " <<v1.back()<<endl;
    cout<<"At Pos 4 ="<<v1.at(4)<<endl;
    v.pop_back();

    for(auto x:v){
      cout<<x<<" ";
    }

    v.erase(v.begin());
    cout<<endl;
    for(auto x:v){
      cout<<x<<" ";
    }

    return 0;
}
