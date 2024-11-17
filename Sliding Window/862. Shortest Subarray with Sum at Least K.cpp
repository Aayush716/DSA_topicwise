/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3
 

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109

*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int total=0;
        vector<long long> p_sum(n,0);//show all prefix sum 
        deque<int> dq;//store the index of elements who are in increasing order always
        int ans = INT_MAX;
        int j=0;

        while(j<n){

            if(j==0){
                p_sum[j] = nums[j];
            }
            else{
                p_sum[j] = p_sum[j-1] + nums[j];
            }

            if(p_sum[j]>=k){
                ans = min(ans,j-0+1);
            }

            //we can keep shrinking deque because total is >= k 
            while(!dq.empty() && (p_sum[j] - p_sum[dq.front()])>=k){//keep shrinking till condn hold and calculate min 
                ans = min(ans,j-dq.front());
                dq.pop_front();
            }

            //if there is a dip in value in p_sum array we dont consider that index
            while(!dq.empty() && p_sum[j]<=p_sum[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(j);
            j++;
        }

        if(ans==INT_MAX){
            return -1;
        }

        return ans;
    }
};

