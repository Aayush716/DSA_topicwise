#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void traversal(Node *root,map<int,pair<int,int>> &mp,int column,int row){
        if(root==NULL){
            return;
        }
        if(mp.find(column)==mp.end() || (mp.find(column)!=mp.end() && mp[column].first>row)){
        //if unable to find the column then push that value (1st if conditon)
        //if column entry is present but rowlevel of current root is less then existing entry in map then replace it with current(2nd if conditon)
            pair<int,int> p;
            p.first = row;
            p.second = root->data;
            mp[column] = p;  //maps key is column and value is pair whose entry is (row,data)
        }
       
        traversal(root->left,mp,column-1,row+1);
        traversal(root->right,mp,column+1,row+1);  
    }
    
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int,pair<int,int>> mp;
        traversal(root,mp,0,0);
        for(auto &x : mp){
            ans.push_back((x.second).second);
            
        }
        return ans;
    }

};

