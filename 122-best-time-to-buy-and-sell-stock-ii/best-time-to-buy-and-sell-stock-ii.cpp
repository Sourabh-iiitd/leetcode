class Solution {
public:
    int dp[30001][2];
    
    int helper(int idx, int buy,vector<int>& prices){
        if(idx==prices.size()) return 0;
        int profit=0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            int by=-prices[idx]+helper(idx+1,0,prices);
            int notbuy=helper(idx+1,1,prices);
            profit=max(by,notbuy);
        }
        else{
            int sell=prices[idx]+helper(idx+1,1,prices);
            int notsell=helper(idx+1,0,prices);
            profit=max(sell,notsell);
        }
        return  dp[idx][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return helper(0,1,prices);
    }
};