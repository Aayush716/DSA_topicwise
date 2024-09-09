/*
You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
https://leetcode.com/problems/spiral-matrix-iv/description/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m,vector<int>(n,-1));
        ListNode* temp = head;
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottum = m-1; 
        while(temp!=NULL){
            for(int j=left;j<=right;j++){
                mat[top][j] = temp->val;
                temp = temp->next;
                if(temp==NULL){
                    return mat;
                }
            }
            top++;
         //   cout<<"top = "<<top<<endl;
            for(int i=top;i<=bottum;i++){
                mat[i][right] = temp->val;
                temp = temp->next;
                if(temp==NULL){
                   return mat;
                }
            }
            right--;
           // cout<<"right = "<<right<<endl;
            for(int j=right;j>=left;j--){
                mat[bottum][j] = temp->val;
                temp =temp->next;
                if(temp==NULL){
                   return mat;
                }
            }
            bottum--;
          //  cout<<"bottum = "<<bottum<<endl;
            for(int i=bottum;i>=top;i--){
                mat[i][left] = temp->val;
                temp = temp->next;
                if(temp==NULL){
                   return mat;
                }
            }
            left++;
          //  cout<<"left = "<<left<<endl;
        }

        return mat;
    }
};