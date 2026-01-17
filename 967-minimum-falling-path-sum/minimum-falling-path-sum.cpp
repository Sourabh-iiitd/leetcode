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
        int k2 = INT_MAX;
        int k3 = INT_MAX;
        if (next - 1 >= 0) {
            k1 = matrix[row][next] + helper(matrix, row + 1, next - 1,dp);
        }
        k2 = matrix[row][next] + helper(matrix, row + 1, next,dp);
        if (next + 1 < matrix[0].size()) {
            k3 = matrix[row][next] + helper(matrix, row + 1, next + 1,dp);
        }

        return dp[row][next] = min(k1, min(k2, k3));
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