/*
https://practice.geeksforgeeks.org/contest/gfg-weekly-173-rated-contest/problems
good question
make a tree from edges and count number of subtrees.

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  
    //mp key = node and value = number of children including itself
    void dfs(int node,vector<int> adj[],vector<int> &visited,unordered_map<int,int> &mp){
        visited[node]=1;//make the node 
        mp[node]=1;//the node itself
        for(int i=0;i<adj[node].size();i++) {
            if(!visited[adj[node][i]]){
                dfs(adj[node][i],adj,visited,mp);
                mp[node] += mp[adj[node][i]]; //keep adding children subtree here
            }
        }    
    }
    
    long long getCount(int n, vector<vector<int>> &edges, int x, int y) {
        //apply dfs
        vector<int> visited(n+1);
        vector<int> adj[n+1];
        
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }//made the adjacency list
        
        unordered_map<int,int> mp;//node and its frequency of elements
        dfs(1,adj,visited,mp);//calling dfs fron node=1
        
        int count_x=0;
        int count_y=0;
        
        for(auto a: mp){
            //cout<<"node = "<<x.first<<" subtree = "<<x.second<<endl;
            if(a.second==x){
                count_x++;
            }
            if(a.second==y){
                count_y++;
            }
        }
        
        return (long long)count_x*count_y;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<vector<int>> edges(n - 1, vector<int>(2));
        Matrix::input(edges, n - 1, 2);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        long long res = obj.getCount(n, edges, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends