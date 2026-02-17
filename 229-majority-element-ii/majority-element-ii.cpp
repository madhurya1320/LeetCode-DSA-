class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>result;
       int n = nums.size(); int m1 = -1; int m2 = -1; int c1 =0; int c2 = 0;

        for(int num : nums) {
            if(num == m1) {
                c1++;
            }
            else if(num == m2) {
                c2++;
            } 
            else if(c1 == 0) {
                m1 = num;
                c1 = 1;
            } else if(c2 == 0) {
                m2 = num;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }
        c1 = 0; c2 = 0;
        for(int i =0; i<nums.size(); i++) {
            if(m1 == nums[i]) {
                c1++;
            } else if(m2 ==nums[i]) {
                c2++;
            }
        }
        if(c1>n/3) {
            result.push_back(m1);
        } 
        if(c2>n/3) {
                result.push_back(m2);
            }
        return result;
    }
};