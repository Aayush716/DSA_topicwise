/*
Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return true If you can find a way to do that or false otherwise.

 

Example 1:

Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
Example 2:

Input: arr = [1,2,3,4,5,6], k = 7
Output: true
Explanation: Pairs are (1,6),(2,5) and(3,4).
Example 3:

Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
 
*/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;

        for(auto x: arr){
            int rem = x%k;
           // cout<<"for x = "<<x<<" rem = "<<rem<<endl;
            if(rem<0){
                rem = (rem+k)%k;
             //   cout<<"for -ve rem = "<<rem<<endl;
            }
            mp[rem]++;
        }

        //if 0 is the remainder then its pair is the number itself with remained 0 hence count must be even
        if(mp[0]%2!=0){
            return false;
        }

        for(int a=1;a<=k/2;a++){
            int b = k-a;
            if(mp[a]!=mp[b]){
                return false;
            }
        }

        return true;
    }
};
