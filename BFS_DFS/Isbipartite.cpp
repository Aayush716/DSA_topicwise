#include <iostream>
using namespace std;


class Solution {
public:

    int flag=0;
    
    bool allvisited(vector<int> &visited){
        for(auto x: visited){
            if(x==0){
                return false;
            }
        }
        return true;
    }

    bool check_adjacent_color(int node, vector<vector<int>> &graph, vector<int> &color){
        int mycolor = color[node];
        for(auto x: graph[node]){
            if(color[x]==mycolor){
                return false;
            }
        }
        return true;
    }

    void DFS(int parent, vector<vector<int>> &graph,vector<int> &visited ,vector<int> &color){
        if(flag==1){
            return;
        }
        for(auto x: graph[parent]){
            if(!visited[x]){
                visited[x]=1;
                color[x] = !color[parent];
                if(check_adjacent_color(x,graph,color)==false){
                    cout<<"node "<<x<<" has adjacent same color"<<endl;
                    flag=1;
                    return;
                }
                DFS(x,graph,visited,color);
                if(flag==1){
                    return;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> color(n,-1);//intially all nodes are not colored
        int start=-1;
        while(!allvisited(visited)){
            start++;
            color[start]=0;//color the 1st node as 0
            visited[start]=1;
            DFS(start,graph,visited,color);
            if(flag==1){
                return false;
            }
        }    
        return true;
    }
};