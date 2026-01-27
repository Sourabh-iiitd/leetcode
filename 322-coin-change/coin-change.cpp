class Solution {
    int dp[13][10001];
public:
    int helper(vector<int>& coins,int idx, int amount){
        if(idx>=coins.size()){
            return 1e9;
        }
        if(amount==0) return 0;
        if(amount<0) return 1e9;
        if (dp[idx][amount] != -1) return dp[idx][amount];
        int take=1+helper(coins,idx,amount-coins[idx]);
        // c++;
        int nt= 0+helper(coins,idx+1,amount);
        
        return dp[idx][amount]=min(take,nt);

    }
    int coinChange(vector<int>& coins, int amount) {
        // int c=0;
        memset(dp, -1, sizeof(dp));
        if(helper(coins,0,amount)>=1e9) return -1;
        return helper(coins,0,amount);
        

    }
};