class Solution {
public:
    int MOD=1e9+7;
    int helper(int n,vector<int> &dp){
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        long long ans=(2LL*helper(n-1,dp)+helper(n-3,dp))%MOD;
        return dp[n]=ans;
    }
    int numTilings(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};