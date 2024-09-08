//Here there is no use of visited array actually

/*1) We find indegree of all nodes by maintaining a indegree array
  2) push nodes with indegree = 0 in queue (because these are nodes from where we begin topo order)
  3) check adjaceny nodes of our poped element and REDUCE ITS indegree accordingly - very important to reduce indegree
  4) push nodes with indegree exactly equal to 0 in queue before that dont push them - remmber important
  5) store topological order in ans before poping the node from queue.  */


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    //1st queue has nodes that have indegree = 0.
    private:
    void Topo_BFS(int V,vector<int> adj[],vector<int> &visited,vector<int> &ans){
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto x: adj[i]){
                indegree[x]++;
            }
        }//calculate indegree for each node
        
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }//push only nodes with indegree = 0
        
       while(!q.empty()){
           int curr_node = q.front();
           for(auto x: adj[curr_node]){
                indegree[x]--;
                if(indegree[x]==0){
                   q.push(x);
                }
           }
           visited[curr_node]=1;
           ans.push_back(curr_node);
           q.pop();
       }
       
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V,0);
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            Topo_BFS(V,adj,visited,ans);
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}
