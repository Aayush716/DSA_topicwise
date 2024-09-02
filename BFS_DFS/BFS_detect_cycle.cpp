//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detect_cycle(vector<int> adj[], vector<int> &visited, int node){
        queue<pair<int,int>> q;
        visited[node]=1;
        q.push({node,-1});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int node = q.front().first;
                int prevnode = q.front().second;
                for(auto x: adj[node]){
                    if(!visited[x]){
                        visited[x]=1;
                        q.push({x,node});
                    }
                    else if(visited[x]==1 && x!=prevnode){
                        return true;//there exist a cycle hence return true
                    }
                }
                q.pop();
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detect_cycle(adj,visited,i)){
                    return true;
                }
            }
        }    
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends