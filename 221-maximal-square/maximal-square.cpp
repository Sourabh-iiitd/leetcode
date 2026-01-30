class Solution {
public:
    int dp[301][301];

    int helper(vector<vector<char>>& matrix, int i, int j) {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;

        if (matrix[i][j] == '0')
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = helper(matrix, i, j + 1);
        int down  = helper(matrix, i + 1, j);
        int diag  = helper(matrix, i + 1, j + 1);

        return dp[i][j] = 1 + min(right, min(down, diag));
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, helper(matrix, i, j));
            }
        }
        return ans * ans;
    }
};
