#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> s; //sets are stored in sorted manner and are always 'unique';
    s.insert(4);
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(2);

    int size = s.size();
    set<int>:: iterator itr = s.begin();
    for(int i=0;i<size;i++){
        cout<<*(itr)<<" ";
        itr++;
    }

    cout<<"\n printing using auto function\n";
    for(auto x: s){
        cout<<x<<" ";
    }
    return 0;
}