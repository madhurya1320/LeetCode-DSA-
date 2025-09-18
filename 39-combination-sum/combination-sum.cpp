class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>arr;
        helper(0, candidates, arr, res, target);
        return res;   
    }

    void helper(int i, vector<int>&nums, vector<int>&arr, vector<vector<int>>&res, int target) {
        if(target == 0) {
            res.push_back(arr);
            return;
        }
        if(i == nums.size()) return;
        if(nums[i] <= target) {
            arr.push_back(nums[i]);
            helper(i, nums, arr, res, target - nums[i]);
            arr.pop_back();
        }
        helper(i+1, nums, arr, res, target);
    }
};