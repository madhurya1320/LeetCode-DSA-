class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int maxi = 0;
        int profit;

        for(int i = 1; i<n; i++) {
            profit = prices[i] - mini;
            maxi = max(maxi, profit);
            mini = min(mini, prices[i]);
        }
        return maxi;
    }
};