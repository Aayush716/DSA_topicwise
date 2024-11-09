/*
You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.

Return the minimum possible value of nums[n - 1].

 

Example 1:

Input: n = 3, x = 4

Output: 6

Explanation:

nums can be [4,5,6] and its last element is 6.

Example 2:

Input: n = 2, x = 7

Output: 15

Explanation:

nums can be [7,15] and its last element is 15.

 

Constraints:

1 <= n, x <= 108
*/

class Solution {
public:
    long long minEnd(int n, int x) {
        // //we need to keep the set bits of x as it is
        // //change the unset bits from right to  left of x fill n-1(binary) from right to left
        // //that will be number 

       
        // vector<int> binary_n;
        // int temp = n-1;
        
        // while(temp!=0){
        //     binary_n.push_back(temp%2);
        //     temp = temp/2;
        // }//binary_n has n-1 in binary form now we need to fill this in x wherever x's bits are unset

        // reverse(binary_n.begin(),binary_n.end());

        // cout<<"binary_n has "<<endl;
        // for(auto x: binary_n){
        //     cout<<x<<endl;
        // }

        // long long ans = x;
        // int count=0;
        // int n1 = binary_n.size()-1;
        // long long i=0;
        // while(n1!=-1){
        //     if((ans & 1<<i)==0){//if ans bit is unset fill the value from binary_n
        //         cout<<"before set ans = "<<ans<<endl;
        //         int val = binary_n[n1];
        //         if(val==1){
        //             ans = ans | 1<<i;//made that bit set
        //             cout<<"after set ans = "<<ans<<endl;
        //         }
        //         n1--;
        //     }
        //     i++;
        // }

        // return ans;
        long result = x;
        long remaining = n - 1;
        long position = 1;
        
        while (remaining) {
            if (!(x & position)) {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }
        
        return result;



    }
};

