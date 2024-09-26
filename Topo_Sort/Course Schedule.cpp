/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //all courses can be taken if this is directed acyclic graph(perfect topological sequence exist)
        //find a topo order and if its size less than numCourses then false if equal then true

        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }//adjacency list formed

        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto x: adj[i]){
                indegree[x]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }//push nodes with indegree 0 because that is where we begin

       vector<int> ans;
       while(!q.empty()){
            int curr_node = q.front();
            ans.push_back(curr_node);
            q.pop();
            for(auto x: adj[curr_node]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
       }

       if(ans.size()<numCourses){
            return false;
       }

        return true;
    }
};
