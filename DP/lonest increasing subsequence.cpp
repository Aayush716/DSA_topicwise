/*
https://leetcode.com/problems/longest-increasing-subsequence/description/

Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/
class Solution {
public:
    int n;
    int fun(int index,int prev,vector<int> &nums,vector<vector<int>> &dp){

        if(index==n-1){
            //because we are accessing numsp[prev] make sure prev should not be -1
            if(prev!=-1 && nums[index]>nums[prev]){
                return 1;
            }
            return 0;
        }

        //we do a coordintae shift in prev hence +1 is always used
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }

        int not_take = fun(index+1,prev,nums,dp);
        int take = INT_MIN;
        if(prev==-1 || nums[index]>nums[prev]){
            take = 1 + fun(index+1,index,nums,dp);
        }
       
        return dp[index][prev+1] = max(take,not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        if(n==1){
            return 1;
        }
        //because prev starts from -1 and go till n-1 we cannot use -1
        //hence e do coordinate shift and prev index in dp is from 0 to n -> coordinate shift striver
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
        return fun(0,-1,nums,dp);

    }
};


