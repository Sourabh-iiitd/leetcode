class Solution {
    int MOD=1e9+7;
    int dp[1001][1001][2];

    int solve(int i, int k, bool taken, int n) {
       if (k==0) return 1;
       if (i>=n) return 0;
       if (dp[i][k][taken] != -1) return dp[i][k][taken];
       long long ans=0;

        if (!taken) {
            
            ans=(ans+solve(i+1, k, false, n)) % MOD;
            
            ans=(ans+solve(i+1, k, true, n)) % MOD;
        } else {
           
            ans=(ans+solve(i+1, k, true, n)) % MOD;
            
            ans=(ans+solve(i, k - 1, false, n)) % MOD;
        }

        return dp[i][k][taken]=ans;
    }

public:
    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, k, false, n);
    }
};