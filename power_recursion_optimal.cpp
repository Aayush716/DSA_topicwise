#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 10;
    int x = 2;
    int ans = 1;
    while(n){
        if(n%2){//only when n is odd
            ans = ans*x;
            n--;
        }
        else{
            x = x*x;
            n=n/2;
        }
    }
    cout<<"\nanswer is = "<<ans;
    return 0;
}