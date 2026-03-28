class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int helper(int i, int j, int xr, vector<vector<int>>& grid) {
        if(i == n-1 && j == m-1) {
            return xr ^ grid[i][j];
        }

        if(dp[i][j][xr] != -1) return dp[i][j][xr];

        int curr = xr ^ grid[i][j];
        int ans = INT_MAX;

        if(j + 1 < m)
            ans = min(ans, helper(i, j+1, curr, grid));

        if(i + 1 < n)
            ans = min(ans, helper(i+1, j, curr, grid));

        return dp[i][j][xr] = ans;
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(8192, -1)));

        return helper(0, 0, 0, grid);
    }
};