class Solution {
    int dp[301][5001];
public:
    int helper(vector<int>& coins,int idx, int amount){
        if(idx==coins.size()){
            return 0;
        }
        if(amount==0) return 1;
        if(amount<0) return 0;
        if (dp[idx][amount] != -1) return dp[idx][amount];
        int take=helper(coins,idx,amount-coins[idx]);
        // c++;
        int nt= helper(coins,idx+1,amount);
        
        return dp[idx][amount]=take+nt;

    }
    int change( int amount,vector<int>& coins) {
        // int c=0;
        memset(dp, -1, sizeof(dp));
        // if(helper(coins,0,amount)) return -1;
        return helper(coins,0,amount);
        

    }
};