class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = 0; int n = nums.size();
        for(int i = 0; i<nums.size(); i++) {
            tot = tot + nums[i];  
        }
        if(tot % 2 != 0) return false;
        int t = tot/2;
        
        vector<vector<bool>>dp(n, vector<bool>(t+1, false));

        for(int i = 0; i<n; i++) {
            dp[i][0] = true;
        }
        if(nums[0] <= t ) {
            dp[0][nums[0]] = true;
        }

        for(int i = 1; i<n; i++) {
            for(int j = 1; j<=t; j++) {
                bool np = dp[i-1][j];
                bool p = false;
                if(nums[i] <= j) {
                    p = dp[i-1][j - nums[i]];
                }
                dp[i][j] = (p || np);
            }
        }
    return dp[n-1][t];
    }
};