class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);

        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i<adj.size(); i++) {
            for(auto de : adj[i]) {
                indegree[de]++;
            }
        }
        queue<int>q;
        for(int i = 0; i<indegree.size(); i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()) {
            int node = q.front(); 
            topo.push_back(node);
            q.pop();

            for(auto n : adj[node]) {
                indegree[n]--;
                if(indegree[n] == 0) {
                    q.push(n);
                }
            }
        }
        if(topo.size() != numCourses) {
             return {};
        }
        return topo;
    }
};