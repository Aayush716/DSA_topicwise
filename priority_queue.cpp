#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq;  //(internally implemented as tree) stores element like in a max heap
    pq.push(2);
    pq.push(5);
    pq.push(3);
    pq.push(1);
    pq.push(4);  //in priority queue element with highest value is at top and decreases gradually (hence pq is also called max heap)
    cout<<"\ntop() prints the element that is at the top\n";
    cout<<pq.top()<<endl;
    int size  = pq.size();
    for(int i=0;i<size;i++){   //if we have used i<pq.size(); in for loop then size of pq.size() will change after every iteration since each time it will get pop
        cout<<pq.top()<<" ";
        pq.pop(); //pops element at the top
    } 
    
    return 0;
}