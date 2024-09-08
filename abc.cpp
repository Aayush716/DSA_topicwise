#include <bits/stdc++.h>
using namespace std;


int main(){

    int t,a,b,c;
    cin>>t;
    cin>>a;
    cin>>b;
    cin>>c;

    //minimize the difference
    //multiset<int> s;
    vector<int> nums;
    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(c);
    sort(nums.begin(),nums.end());
    int diff1 = nums[1] - nums[0];
    int diff2 = nums[2] - nums[1];
    int count=0;
    while(count!=5){
        if(diff1)
    }

}