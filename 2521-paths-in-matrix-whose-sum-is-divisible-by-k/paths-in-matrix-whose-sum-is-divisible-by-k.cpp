class Solution {
public:
    int mod = 1e9+7;
    int n, m;

    int dfs(int i, int j, int rem, vector<vector<int>>& grid, int k,
            vector<vector<vector<int>>>& dp) {
        if(i >= n || j >= m) return 0;
        rem = (rem + grid[i][j]) % k;
        if(i == n-1 && j == m-1) {
            return (rem == 0);
        }
        if(dp[i][j][rem] != -1) return dp[i][j][rem];

        int right = dfs(i, j+1, rem, grid, k, dp);
        int down  = dfs(i+1, j, rem, grid, k, dp);

        return dp[i][j][rem] = (right + down) % mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));

        return dfs(0, 0, 0, grid, k, dp);
    }
};