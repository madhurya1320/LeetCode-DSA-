class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(helper(vector<int>(nums.begin() + 1, nums.end())),helper(vector<int>(nums.begin(), nums.end() - 1)) );
        
    }

    int helper(vector<int> nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int>dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i<nums.size(); i++) {
            int p = nums[i] + dp[i-2];
            int np = dp[i-1];
            dp[i] = max(p, np);
        }
        return dp[nums.size()-1];

    }
};