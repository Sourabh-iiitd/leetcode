class Solution {
public:
    int helper(vector<vector<int>>& matrix, int row, int next,vector<vector<int>> &dp) {
        if (row == matrix.size() - 1) {
            return matrix[row][next];
        }
        if(dp[row][next]!=INT_MAX){
            return dp[row][next];
        }
        int k1 = INT_MAX;
        
        for(int i=0;i<matrix[0].size();i++){
            if(i!=next){
                int n=matrix[row][next]+helper(matrix,row+1,i,dp);
                k1=min(k1,n);
            }
        }

        return dp[row][next] = k1;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        int ans = INT_MAX;
        for (int i = 0; i < matrix[0].size(); i++) {
            ans = min(ans, helper(matrix,0,i,dp));
        }
        return ans;
    }
};