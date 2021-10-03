#include<iostream>
#include<cstring>
#include<map>

using namespace  std;

int main(int argc, char const *argv[])
{
    map<int, int> mp;
    map<int, int>::iterator it;
    mp.insert(pair<int, int>(10, 301));
    mp.insert(pair<int, int>(11, 310));
    mp.insert(pair<int, int>(13, 230));
    mp.insert(pair<int, int>(15, 302));
    mp.insert(pair<int, int>(17, 320));
    for(it = mp.begin(); it!=mp.end(); it++){
        cout<<it->first<<" " <<it->second<<endl;
    }
    map<int, int>::iterator itr;
    itr = mp.find(10);
    cout<<itr->second;
    cout<<endl;
    cout<<"count of 000: "<<mp.count(000);
    cout<<endl;
    map<int, int>::iterator itr1;

    // case when lower_bound is found
    itr1 = mp.lower_bound(11);
    cout<<" Case When lower bound is found: "<<itr1->second<<endl;

    // case when lower bound is not found and it return
    // the iterator to the next element
    itr1 = mp.lower_bound(12);
    cout<<" case when key is not present: "<<itr1->second<<" "<<endl;
    itr1 = mp.lower_bound(18);
    cout<<" case when key is out of order: "<<itr1->first<<" "<<itr1->second<<" "<<endl;
    cout<<endl;
    return 0;
}
