#include <bits/stdc++.h>
using namespace std;

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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        //no need to manage visited since this is not BFS Traversal this is level order traversal
        //important here is how to use queue to keep nodes of that particular level
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;//this vector has elements only for that particular level ,reintalized when level arrives in tree
            for(int i=0;i<size;i++){//this loop stores nodes of particulr level only
            //at each level number of nodes = size of queue
            //null nodes are not pushed in queue hnce no nee to worry about them
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                level.push_back(temp->val);
            }
            ans.push_back(level);//each level nodes are pushed to final ans
        }

        return ans;
    }
};