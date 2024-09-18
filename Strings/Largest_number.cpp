/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109

https://leetcode.com/problems/largest-number/description/
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        

        //lambda function
        auto mycomparator = [](int &a,int &b){
            string s1 = to_string(a);//to_string converts integer to string
            string s2 = to_string(b);

            if(s1+s2>s2+s1){//we are checking whether first number is greater or second one
                return true;
            }
            return false;
        };

        sort(begin(nums),end(nums),mycomparator);

        //now our nums is sorted according to largest number
        if(nums[0]==0){
            return "0";
        }
        
        string result;
        for(auto a: nums){
            result += to_string(a);
        }
        return result;
    }
};