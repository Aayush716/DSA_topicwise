/*
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

 

Example 1:


Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
Example 2:


Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 104
*/

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL)
            return root;

        queue<TreeNode*> que;
        que.push(root);
        vector<int> levelSum;

        //Step-1 (find sum of each level and store in levelSum array)
        while(!que.empty()) {
            int currLevelSum = 0;
            int n = que.size();
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                currLevelSum += curr->val;
                if(curr->left) {
                    que.push(curr->left);
                }
                if(curr->right) {
                    que.push(curr->right);
                }
            }

            levelSum.push_back(currLevelSum);
        }
        cout << levelSum.size() << endl;

        //Step-2 (update each node value with cousin sum)
        que.push(root);
        root->val = 0; //root has not cousins
        int i = 1;
        while(!que.empty()) {
            int n = que.size(); //current level me kitne nodes hain

            while(n--) {
                TreeNode* curr = que.front();
                que.pop();

                //levelSum of currentLevel - sibilnigSum
                int siblingSum = curr->left != NULL ? curr->left->val : 0;
                siblingSum += curr->right != NULL ? curr->right->val : 0;

                if(curr->left) {
                    curr->left->val = levelSum[i] - siblingSum;
                    que.push(curr->left);
                }
                if(curr->right) {
                    curr->right->val = levelSum[i] - siblingSum;
                    que.push(curr->right);
                }
            }
            i++;
        }

        return root;

    }
};


