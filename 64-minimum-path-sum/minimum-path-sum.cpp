class Solution {
public:
    long long helper(vector<vector<int>>& grid,int i, int j,vector<vector<int>> &dp){
        if(i<0 || j<0) return INT_MAX;
        if(i==0 && j==0) {
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        long long k1=grid[i][j] + helper(grid,i-1,j,dp);
        long long k2=grid[i][j] + helper(grid,i,j-1,dp);
        return dp[i][j]=min(k1,k2);
    }
    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return helper(grid,m-1,n-1,dp);
    }
};