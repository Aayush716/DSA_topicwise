/*

Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.
Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  
https://leetcode.com/problems/linked-list-in-binary-tree/description/
Leetcode 1367.
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans = false;

    bool DFS(TreeNode* root, ListNode* head){

        bool LEFT = false;
        bool RIGHT = false;

        if(head->next==NULL && root->val==head->val){//I am on the last node that is equal
            return true;
        }
        if(root->left && head->next && root->left->val==head->next->val){
            LEFT = DFS(root->left,head->next);    
        } 
        if(root->right && head->next && root->right->val==head->next->val){
            RIGHT = DFS(root->right,head->next);
        }
        return LEFT|RIGHT;//if any one if true the whole answer will be true
    }
  

    void Travel(TreeNode* root,ListNode* head){
        if(root==NULL){
            return;
        }
        if(root->val==head->val){
            cout<<"DFS with 1st element equal "<<endl;
            if(DFS(root,head)){
                ans = true;
                return;
            }
        }

        Travel(root->right,head);
        Travel(root->left,head);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        Travel(root,head);
         return ans;
    }
};