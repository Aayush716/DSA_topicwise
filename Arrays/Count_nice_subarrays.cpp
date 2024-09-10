/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        //replace even number with 0 and odd with 1
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }

        //problem changed to number of subarray with sum=k
        //use a map to store sum and frequency of sum
        map<int,int> mp;//  {sum , frequency}
        mp[0]=1;//important step
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(mp.find(sum-k)!=mp.end()){//found subarray of sum-k then add
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};