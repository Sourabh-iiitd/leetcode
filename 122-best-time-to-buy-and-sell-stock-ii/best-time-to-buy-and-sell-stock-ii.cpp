class Solution {
public:
    int dp[30001][2];

    // int helper(int idx, int buy, vector<int>& prices) {
    //     if (idx == prices.size())
    //         return 0;
    //     int profit = 0;
    //     if (dp[idx][buy] != -1)
    //         return dp[idx][buy];
    //     if (buy) {
    //         int by = -prices[idx] + helper(idx + 1, 0, prices);
    //         int notbuy = helper(idx + 1, 1, prices);
    //         profit = max(by, notbuy);
    //     } else {
    //         int sell = prices[idx] + helper(idx + 1, 1, prices);
    //         int notsell = helper(idx + 1, 0, prices);
    //         profit = max(sell, notsell);
    //     }
    //     return dp[idx][buy] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        dp[n][0] = dp[n][1] = 0;
        for(int idx=n-1;idx>=0;idx--){
            for (int j = 0; j < 2; j++) {
                int profit = 0;
               
                if (j==1) {
                    int by = -prices[idx] + dp[idx+1][0];
                    int notbuy = dp[idx+1][j];
                    profit = max(by, notbuy);
                } else {
                    int sell = prices[idx] + dp[idx + 1][1];
                    int notsell = dp[idx + 1][0];
                    profit = max(sell, notsell);
                }
                dp[idx][j] = profit;
            }
        }
        return dp[0][1];
    }
};