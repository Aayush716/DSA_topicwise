/*
You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).

Return an array answer where answer[i] is the answer to the ith query.

 

Example 1:

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
Example 2:

Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]

*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix_xor;
        int temp = 0;
        for(int i=0;i<n;i++){
            temp = temp^arr[i];
            prefix_xor.push_back(temp);
        }
        //now prefix xor is from [0,0] , [0,1] , [0,2] , [0,3] ,.....
        //if in querie our left is 0 then answer is staright forward prefix_xor[right]
        //if in querie left is not 0 then we need to calculate prefix[right] ^ prefix[left-1]
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int right = queries[i][1];
            int left = queries[i][0];
            if(left==0){
                ans.push_back(prefix_xor[right]);//because left is 0
            }
            else{
                ans.push_back(prefix_xor[right]^prefix_xor[left-1]);
            }
        }

        /*example to calculate querie[1,2] = prefix_xor[2] ^ prefix_xor[1-1]
        another example querie[2,3] = prefix_xor[3] ^ prefix_xor[2-1]
        (prefix_xor[right] ^ prefix_xor[left-1]) when left is not 0.
        */

        return ans;
    }
};