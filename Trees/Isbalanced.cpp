#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool result = true;

    int maxDepth(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        return max(maxDepth(node->left),maxDepth(node->right))+1;
    }

    void preorder(TreeNode* root){

        if(root==NULL || result==false){//enen if result==false is not there code works fine
            return;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if((left-right)>1 || (right-left)>1){
            result = false;//cannot be changed
        }
        preorder(root->left);
        preorder(root->right);
    }

    bool isBalanced(TreeNode* root) {
        preorder(root);//travel to each node 
        //and check hight diff of its left,right
        return result;
    }
};