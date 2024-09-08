//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void DFS(int node,vector<int> adj[],vector<int> &visited,stack<int> &st){
        //cout<<"DFS of "<<node<<endl;
        for(auto x: adj[node]){
            if(!visited[x]){
                visited[x]=1;
                DFS(x,adj,visited,st);
            }
        }
        
        st.push(node);//push in stack only when no further DFS call to adjacent of node (node is exhausted) 
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V,0);
	    stack<int> st;//store the order for topological sort
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            visited[i]=1;
	            DFS(i,adj,visited,st);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};
