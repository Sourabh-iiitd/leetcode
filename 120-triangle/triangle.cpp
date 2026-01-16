class Solution {
public:
    int pathsm(vector<vector<int>>& triangle,int i,int j,vector<vector<int>> &dp){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        // int k1=INT_MAX:
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int k1=triangle[i][j]+pathsm(triangle,i+1,j,dp);
        int k2=triangle[i][j]+pathsm(triangle,i+1,j+1,dp);
        return dp[i][j]=min(k1,k2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MIN));
        return pathsm(triangle,0,0,dp);
    }
};