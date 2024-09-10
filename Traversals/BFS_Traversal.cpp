#include <bits/stdc++.h>
using namespace std;

vector<int> BfsTraversal(vector<vector<int>> &adj, int n){
    int start=0;
    int visted[n]={0};//no vertices are not visted intially
    queue<int> q;
    q.push(start);
    visted[start]=1;//start node is visted

    vector<int> bfs;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        bfs.push_back(element);//the poping out sequence is only bfs traversal

        for(int i=0;i<n;i++){
            if(adj[element][i]==1 && !visited[adj[element][i]]){//if adjacent to element is found and is not visited then push in queue and mark visited
                q.push(adj[element][i]);//push in queue
                visted[adj[element][i]]=1;//mark it visted
            }
        }
    }

    return bfs;
}

//one way to keep adjaceny list is vector<int> adj[]
/*we access each node that is adjacent to element by 
for(auto it: adj[element]){ 
    if(!visted[it]){
        q.push(it);
        visited[it]=1;
    }
}

int main(){
   

}