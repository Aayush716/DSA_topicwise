class Solution {
public:
    int flag=0;
    bool Travel(TreeNode* root, vector<TreeNode*> &path, TreeNode* p){
        if(root==NULL){
            return false;
        }
        path.push_back(root);
        if(root==p){
            return true;
        }
        if(Travel(root->left,path,p) || Travel(root->right,path,p)){//if either left,right return true
        //then return true
            return true;
        }
        else{
            path.pop_back();//the pushed node of no use hence need to pop it back
            return false;   //return false since not found that
        }
    }//this logic to find a path from root to node p and path vector stores only that path and rest is removed.

    TreeNode* comparepaths(vector<TreeNode*> &path1,vector<TreeNode*> &path2){
        int n1 = path1.size();
        int n2 = path2.size();
        int p1=0;
        int p2=0;
        int flag2=0;
        while(path1[p1]==path2[p2]){
            if(p1<n1-1){
                p1++;
            }
            else{
                flag2=1;
                break;
            }
            if(p2<n2-1){
                p2++;
            }
            else{
                flag2=2;
                break;
            }
        }
        if(flag2==1){
            return path1[p1];
        }
        else if(flag2==2){
            return path2[p2];
        }
        return path2[p2-1];
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || p==NULL || q==NULL){
            return root;
        }
        vector<TreeNode*> path1;
        bool result1 = Travel(root,path1,p);
        cout<<"after 1st travel"<<endl;
        for(auto x: path1){
            cout<<x->val<<" ";
        }
        cout<<endl;

        flag=0;//renintialize the flag
        vector<TreeNode*> path2;
        bool result2 = Travel(root,path2,q);
        cout<<"after 2nd travel"<<endl;
        for(auto x: path2){
            cout<<x->val<<" ";
        }

        TreeNode* ans = comparepaths(path1,path2);
        return ans;
    }
};