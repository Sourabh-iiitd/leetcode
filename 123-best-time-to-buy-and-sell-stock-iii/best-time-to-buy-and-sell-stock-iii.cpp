class Solution {
public:
     int dp[100001][2][3];

    int helper(int idx, int buy, vector<int>& prices,int cap) {
        if (idx == prices.size() || cap==0)
            return 0;
        int profit = 0;
        if (dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];
        if (buy) {
            int by = -prices[idx] + helper(idx + 1, 0, prices,cap);
            int notbuy = helper(idx + 1, 1, prices,cap);
            profit = max(by, notbuy);
        } else {
            int sell = prices[idx] + helper(idx + 1, 1, prices,cap-1);
            int notsell = helper(idx + 1, 0, prices,cap);
            profit = max(sell, notsell);
        }
        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return helper(0,1,prices,2);
    }
};