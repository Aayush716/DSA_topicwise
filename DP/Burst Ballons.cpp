/*
You are given N balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array arr. You are asked to burst all the balloons.
If you burst the ith balloon, you will get arr[ i - 1 ] * arr[ i ] * arr[ i + 1] coins. If i - 1, or i + 1 goes out of the bounds of the array, consider it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:

Input:
N = 4
arr[ ] = {3, 1, 5, 8}
Output: 167
Explanation: 
arr[ ] = {3, 1, 5, 8}  - - > {3, 5, 8} - - > {3, 8} - - > { 8} - -> { }
coins = 3 *1 *5,      +      3*5*8     +   1*3*8   +  1*8*1   = 167
 
 

Example 2:

Input:
N = 2
arr[ ] = {1, 10}
Output: 20
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCoins() which takes the array of integers arr and N as parameters and returns the maximum coin you can collect.

Expected Time Complexity: O(N*N*N)
Expected Auxiliary Space: O(N*N)

Constraints:
1 ≤ N ≤ 300
0 ≤ arr [ i ]  ≤ 100

*/
// } Driver Code Ends
class Solution {
public:
    //i is the left and j in right and index is current one.
    int fun(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
        
        if(i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int maxi = INT_MIN;
        
        for(int index=i;index<=j;index++){
            int cost = arr[i-1]*arr[index]*arr[j+1]
            + fun(i,index-1,arr,dp) + fun(index+1,j,arr,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][j] = maxi;
    }
    
    int maxCoins(int N, vector<int> &arr) {
        
        arr.push_back(1);//pushed at last
        arr.insert(arr.begin(),1);//insert before start
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return fun(1,N,arr,dp);
        
    }
};

