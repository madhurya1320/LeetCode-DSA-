class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>arr;
        helper(0, candidates, res, arr, target);
        return res;
    }

    void helper(int i, vector<int>&nums, vector<vector<int>>&res, vector<int>&arr, int target) {
        if(target == 0) {
        res.push_back(arr);
        return;
    }
        for(int j = i; j<nums.size(); j++) {
            if(j>i && nums[j] == nums[j-1]) continue;

            if(nums[j]>target) break;

            arr.push_back(nums[j]);
            helper(j+1, nums, res, arr, target - nums[j]);
            arr.pop_back();
        }

    }
};