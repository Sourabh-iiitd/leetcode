class Solution {
public:

    int helper(vector<vector<int>>& obstacleGrid, int i,int j, vector<vector<int>> &dp){
        if(i<0 || j<0 ) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int k1=helper(obstacleGrid,i-1,j,dp);
        int k2=helper(obstacleGrid,i,j-1,dp);
        return dp[i][j]=k1+k2;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return helper(obstacleGrid,m-1,n-1,dp);
    }
};