/*
You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

In one operation:

choose an index i such that 0 <= i < nums.length,
increase your score by nums[i], and
replace nums[i] with ceil(nums[i] / 3).
Return the maximum possible score you can attain after applying exactly k operations.

The ceiling function ceil(val) is the least integer greater than or equal to val.

 

Example 1:

Input: nums = [10,10,10,10,10], k = 5
Output: 50
Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
Example 2:

Input: nums = [1,10,3,3,3], k = 3
Output: 17
Explanation: You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,1,1,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.
 

Constraints:

1 <= nums.length, k <= 105
1 <= nums[i] <= 109
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-Heap: stores (value, list index, element index)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int curMax = numeric_limits<int>::min();

        // Initialize the heap with the first element of each list
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }
        // Track the smallest range
        vector<int> smallRange = {0, numeric_limits<int>::max()};

        while (!minHeap.empty()) {
            // Get the minimum element from the heap
            vector<int> curr = minHeap.top();
            minHeap.pop();
            int curMin = curr[0], listIdx = curr[1], elemIdx = curr[2];

            // Update the smallest range if a better one is found
            if ((curMax - curMin < smallRange[1] - smallRange[0]) ||
                (curMax - curMin == smallRange[1] - smallRange[0] && curMin < smallRange[0])) {
                smallRange[0] = curMin;
                smallRange[1] = curMax;
            }

            // Move to the next element in the same list
            if (elemIdx + 1 < nums[listIdx].size()) {
                int nextVal = nums[listIdx][elemIdx + 1];
                minHeap.push({nextVal, listIdx, elemIdx + 1});
                curMax = max(curMax, nextVal);
            } else {
                // If any list is exhausted, stop
                break;
            }
        }
        return smallRange;
    }
};
