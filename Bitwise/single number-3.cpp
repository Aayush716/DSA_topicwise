
/*Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:
Input: nums = [-1,0]
Output: [-1,0]   */

#include <iostream>
using namespace std;

class Solution {
public:

    //to finnd a bit that is set in a number method is
    //  1<<i & num  and if this is positive that means ith bit is set(1).
    int find_bit_one(int x_or){//find any bit is '1' because
        for(int i=0;i<INT_MAX;i++){
            if((1<<i)&x_or){
                return i;
            }
        }
        return 0;
    }

    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        //xor of all numbers result in xor of the numbers that are exactly once
        int x_or=0;
        for(int i=0;i<n;i++){
            x_or = x_or^nums[i];
        }
        //we find any bit from xor that is 1 because that is where both numbers would differ
        int bit_positon = find_bit_one(x_or);

        int group0=0;//group with numbers whose bit_positon is 0.
        int group1=0;//group with numbers whose bit_positon is 1.
        for(int i=0;i<n;i++){
            if((1<<bit_positon)&nums[i]){
                group1 = group1 ^ nums[i];
            }
            else{
                group0 = group0 ^ nums[i];
            }
        }

        return {group0,group1};
    }
};