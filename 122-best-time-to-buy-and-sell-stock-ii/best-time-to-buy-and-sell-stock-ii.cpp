class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0; int profit;
        for(int i = 1; i<prices.size(); i++) {
            profit = prices[i] - prices[i-1];
            if(profit > 0) {
            maxi = maxi + profit;
            }
            profit = 0;
        }
        return maxi;
    
    }
};