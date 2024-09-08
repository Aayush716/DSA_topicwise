#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();//just pops dosent return element
    }

    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"trying to print the element from back"
   while(!q.empty()){
        cout<<q.back()<<" ";
        q.pop();
    }
    return 0;
}