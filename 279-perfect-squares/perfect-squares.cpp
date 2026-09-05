class Solution {
public:
    int dp[10001];
    int solve(int n){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int res=solve(n-i*i);
            ans=min(ans,1+res);

        }
        return dp[n]=ans;

    }
    int numSquares(int n) {
        memset(dp,-1, sizeof(dp));
        return solve(n);
    }
};