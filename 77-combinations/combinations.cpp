class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i = 1; i<=n; i++) {
            nums.push_back(i);
        }
        vector<vector<int>>res;
        vector<int>ans;
        helper(0, n, k, res, ans, nums);
        return res;
    }

    void helper(int i, int n, int k, vector<vector<int>>&res, vector<int>&ans,vector<int>&nums) {
        if(i == n) {
            if(ans.size() == k){
                res.push_back(ans);
            }
            return;
        }
        ans.push_back(nums[i]);
        helper(i+1, n, k, res, ans, nums);
        ans.pop_back();
        helper(i+1, n, k, res, ans, nums);
    }
};