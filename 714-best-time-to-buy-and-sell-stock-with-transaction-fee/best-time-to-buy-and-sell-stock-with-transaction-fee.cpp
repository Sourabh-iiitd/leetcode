class Solution {
public:
    int dp[50001][2];
    int helper(int idx,int buy,vector<int>& prices, int fee){
        if(idx==prices.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit=INT_MIN;
        if(buy){
            int by=-prices[idx]+helper(idx+1,0,prices,fee);
            int notby=helper(idx+1,1,prices,fee);
            profit=max(by,notby);
        }
        else{
            int sell=prices[idx]-fee+helper(idx+1,1,prices,fee);
            int notsell=helper(idx+1,0,prices,fee);
            profit=max(sell,notsell);
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return helper(0,1,prices,fee);     
    }
};

