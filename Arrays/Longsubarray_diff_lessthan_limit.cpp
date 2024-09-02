/*
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that
the absolute difference between any two elements of this subarray is less than or equal to limit. 
Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
*/

/*
auto it = mt.find(nums[i]);
mt.erase(it)  
this is the way to delete element from multiset
if we delete it mt.erase(nums[i]) then all the duplicates will also be deleted
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0;
        int j=0;
        int diff=0;
        int ans=0;
        int n = nums.size();
        multiset<int> mt;//store duplicates also and sorted manner also  (multiset is upgrade of set)
        while(i<n && j<n){
            mt.insert(nums[j]);
            diff = *(mt.rbegin()) - *(mt.begin());//max - min
           // cout<<"i = "<<i<<" j = "<<j<<" diff = "<<diff<<endl;
            //remove element from multiset till diff is <= limit
            while(i<n && diff>limit){
                auto it = mt.find(nums[i]);//this iterator will give place 
                mt.erase(it);// if we do mt.erase(nums[i]) duplicate will also be deleted
                diff = *(mt.rbegin()) - *(mt.begin());//max - min
                i++;
                //cout<<"DIFF = "<<diff<<endl;
            }

            ans = max(ans,j-i+1);
            //cout<<"ans = "<<ans<<endl;
            cout<<endl<<endl;
            j++;
        }
        return ans;
    }
};
/*
multiset is a data type that stores duplicates elements but sorted
multiset is a means upgrade of set

always remember to delete a element from multiset:
auto it = mt.find(nums[i]);
mt.erase(it);

*/