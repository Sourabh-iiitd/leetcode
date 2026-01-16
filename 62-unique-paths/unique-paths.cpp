class Solution {
public:
    int helper(int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i==0 || j==0){
            return 1;

        }
        if(dp[i][j]!=-1) return dp[i][j];
        int k1=helper(m,n,i-1,j,dp);
        int k2=helper(m,n,i,j-1,dp);
        return dp[i][j]=k1+k2;


    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return helper(m,n,m-1,n-1,dp);
    }
};