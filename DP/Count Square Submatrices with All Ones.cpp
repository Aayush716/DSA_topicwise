/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

class Solution {
public:

    int n;
    int m;

    int solve(int i,int j,vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(i>=n || j>=m){
            return 0;
        }

        if(matrix[i][j]==0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int right = solve(i,j+1,matrix,dp);
        int digonal = solve(i+1,j+1,matrix,dp);
        int down = solve(i+1,j,matrix,dp);

        return dp[i][j] = 1 + min(right,min(digonal,down));//1 is added because that element itself is 1(1 cross 1 matrix)
    }

    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        int ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    ans += solve(i,j,matrix,dp);
                   // cout<<"for i = "<<i<<"j = "<<j<<" ans = "<<ans<<endl;
                }
            }
        }

        return ans;
    }
};
