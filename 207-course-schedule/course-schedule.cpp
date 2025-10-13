class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size(); //int V = numCourses;
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);

        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i<adj.size(); i++) {
            for(auto n : adj[i]) {
                indegree[n]++;
            }
        }
        queue<int>q;
        for(int i = 0; i<indegree.size(); i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        //vector<int> topo; 
        int finish = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            //topo.push_back(node);
            finish++;
            for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}
        if (finish == numCourses) return true;
		return false;
        }

};