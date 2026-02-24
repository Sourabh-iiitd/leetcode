class Solution {
public:
    int dp[50001][2];
    // int helper(int idx,int buy,vector<int>& prices, int fee){
    //     if(idx==prices.size()){
    //         return 0;
    //     }
    //     if(dp[idx][buy]!=-1) return dp[idx][buy];
    //     int profit=INT_MIN;
    //     if(buy){
    //         int by=-prices[idx]+helper(idx+1,0,prices,fee);
    //         int notby=helper(idx+1,1,prices,fee);
    //         profit=max(by,notby);
    //     }
    //     else{
    //         int sell=prices[idx]-fee+helper(idx+1,1,prices,fee);
    //         int notsell=helper(idx+1,0,prices,fee);
    //         profit=max(sell,notsell);
    //     }
    //     return dp[idx][buy]=profit;
    // }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        int n = prices.size();
        dp[n][1]=dp[n][0]=0;
        
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int j = 0; j < 2; j++) {
              
                // int profit = INT_MIN;
                if (j) {
                    int by = -prices[idx] + dp[idx + 1][0];
                    int notby = dp[idx + 1] [1];
                    dp[idx][j] = max(by, notby);
                } else {
                    int sell =
                        prices[idx] - fee + dp[idx + 1][1];
                    int notsell = dp[idx + 1][0];
                    dp[idx][j] = max(sell, notsell);
                }
            }
        }
        return dp[0][1];
    }
};
