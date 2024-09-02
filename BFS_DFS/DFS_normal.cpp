#include <bits/stdc++.h>
using namespace std;

void dfs(int node , vector<int> adj[], vector<int> &visited ,vector<int> &ans){
        //passed by refrence the adjacency list
        ans.push_back(node);
        for(auto x: adj[node]){ //x has the element of adjacency list one by one
            if(!visited[x]){
                visited[x] = 1;
                dfs(x,adj,visited,ans);
            }
        }
    }
    
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V,0);
    visited[0]=1;
    vector<int> ans;
    dfs(0,adj,visited,ans);
    return ans;
}

