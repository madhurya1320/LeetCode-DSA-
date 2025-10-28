class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<vector<int>>dp(coins.size(), vector<int>(amount+1, 0));
       int n = coins.size();
       for(int i = 0; i<=amount; i++) {
        if(i % coins[0] == 0) {
            dp[0][i] = i/coins[0];
        } else  {
            dp[0][i]= 1e9;
        }
       }
       for(int i = 1; i<coins.size(); i++) {
        for(int j = 0; j<=amount; j++ ) {
            int nt = dp[i-1][j];
            int t = 1e9;
            if(coins[i] <= j) {
                t = 1+ dp[i][j - coins[i]];
            }
            dp[i][j] = min(nt, t);
        }
       }
       int ans = dp[n-1][amount];
       if(ans >= 1e9) {
            return -1;
       } 
       return ans;
    }
};