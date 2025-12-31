class Solution {
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>ans;
        helper(0, nums, res, ans);
        return res;
    }

    void helper(int i, vector<int>&nums, vector<vector<int>>&res, vector<int>&ans) {
        res.push_back(ans);

        for(int j=i; j<nums.size(); j++) {
            if(j>i && nums[j] == nums[j-1]) continue;

            ans.push_back(nums[j]);
            helper(j+1, nums, res, ans);
            ans.pop_back();
        }
    }
};