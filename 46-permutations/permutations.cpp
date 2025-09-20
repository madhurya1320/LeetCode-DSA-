class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>arr;
        helper(0, nums, res);
        return res;
    }

    void helper(int i, vector<int>&nums,vector<vector<int>>&res) {
        if(i == nums.size()) {
            res.push_back(nums);
        }
        for(int j = i; j<nums.size(); j++) {
            swap(nums[i], nums[j]);
            helper(i+1, nums, res);
            swap(nums[i], nums[j]);
        }
    }
};