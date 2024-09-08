#include <bits/stdc++.h>
using namespace std;

/* 
We can implement stack using 2 queues , 3steps need to be followed
1) push a element in q2;
2) transfer all elements from q1 to q2;(this transfer only changes direction of elements in queue)
3) swap all elements from q2 to q1;*/

class MyStack {
public:
    
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
       q2.push(x);//first push the element in q2 intially (tis line is important do not forget)
       while(!q1.empty()){//transfer all emelemnts from q1 to q2 till q1 becomes empty
           q2.push(q1.front());
           q1.pop();
       }
       
       while(!q2.empty()){//transfer all the elements from q2 to q1 
           q1.push(q2.front());
           q2.pop();
       }//swap elements from q2 to q1and make q2 queue empty
    }
    
    int pop() {
        int res = q1.front();
        q1.pop();
        return res;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
