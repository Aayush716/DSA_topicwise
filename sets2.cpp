#include <bits/stdc++.h>
using namespace std;

int main(){

    set<int> s;
    s.insert(6);
    s.insert(5);
    s.insert(2);

    auto pos = s.find(2);//stores positon of place where 2 has been stored
    //if the elemnt we are searching for is not present then pos points at last
    if(pos!=s.end()){
        cout<<"the element has been found"<<endl;
        s.erase(pos);//method to remove the element
    }
    for(auto x:s){
        cout<<x<<" ";
    }

}