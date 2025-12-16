class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum%2 != 0) {
            return false;
        }
        int target = sum/2;
        vector<vector<bool>>dp(nums.size(), vector<bool>(target+1, false));

        for(int i = 0; i<nums.size(); i++) {
            dp[i][0] = true;
        }

        if(nums[0] <=target) {
            dp[0][nums[0]] = true;
        }
        for(int i = 1; i <nums.size(); i++) {
            for(int t = 1; t<=target; t++) {
                bool nt = dp[i-1][t];

                bool ta = false;
                if(nums[i] <= t) {
                    ta = dp[i-1][t - nums[i]];
                }
                dp[i][t] = nt || ta;
            }
        }
        return dp[nums.size()-1][target];


    }
};