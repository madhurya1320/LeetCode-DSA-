class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>arr;
        helper(0, candidates, res, arr, target);
        return res;
    }

    void helper(int ind, vector<int>&nums, vector<vector<int>>&res, vector<int>&arr, int target) {
        if(target == 0) {
        res.push_back(arr);
        return;
    }
        for(int i = ind; i<nums.size(); i++) {
            if(i>ind && nums[i] == nums[i-1]) continue;

            if(nums[i]>target) break;

            arr.push_back(nums[i]);
            helper(i+1, nums, res, arr, target - nums[i]);
            arr.pop_back();
        }

    }
};