class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans = -1;
        vector<int>indegree(n+1, 0);
        vector<int>outdegree(n+1, 0);
        for(int i = 0; i<trust.size(); i++) {
            int var = trust[i][0];
            int var1 = trust[i][1]; 
            indegree[var]++;
            outdegree[var1]++;

        }

        for(int i = 1; i<indegree.size(); i++) {
            if(indegree[i] == 0 & outdegree[i] == n-1) {
                ans = i;
                break;
            }
       
        }
        return ans;
    }
};