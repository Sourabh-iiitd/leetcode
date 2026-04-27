class Solution {
public:
    vector<vector<int>> grid;
    int m, n;
    vector<vector<int>> vis;

    bool solve(int i, int j) {
        if (i == n - 1 && j == m - 1)
            return true;

        vis[i][j] = 1;

        int curr = grid[i][j];
        bool ans = false;

        
        if (curr == 1) {
            if (j + 1 < m) {
                int ni = i, nj = j + 1;
                if (!vis[ni][nj] && (grid[ni][nj] == 1 || grid[ni][nj] == 3 ||
                                     grid[ni][nj] == 5))
                    ans = ans || solve(ni, nj);
            }
            if (j - 1 >= 0) {
                int ni = i, nj = j - 1;
                if (!vis[ni][nj] && (grid[ni][nj] == 1 || grid[ni][nj] == 4 ||
                                     grid[ni][nj] == 6))
                    ans = ans || solve(ni, nj);
            }
        }

       
        else if (curr == 2) {
            if (i + 1 < n) {
                int ni = i + 1, nj = j;
                if (!vis[ni][nj] && (grid[ni][nj] == 2 || grid[ni][nj] == 5 ||
                                     grid[ni][nj] == 6))
                    ans = ans || solve(ni, nj);
            }
            if (i - 1 >= 0) {
                int ni = i - 1, nj = j;
                if (!vis[ni][nj] && (grid[ni][nj] == 2 || grid[ni][nj] == 3 ||
                                     grid[ni][nj] == 4))
                    ans = ans || solve(ni, nj);
            }
        }

        
        else if (curr == 3) {
            if (i + 1 < n) {
                int ni = i + 1, nj = j;
                if (!vis[ni][nj] && (grid[ni][nj] == 2 || grid[ni][nj] == 5 ||
                                     grid[ni][nj] == 6))
                    ans = ans || solve(ni, nj);
            }
            if (j - 1 >= 0) {
                int ni = i, nj = j - 1;
                if (!vis[ni][nj] && (grid[ni][nj] == 1 || grid[ni][nj] == 4 ||
                                     grid[ni][nj] == 6))
                    ans = ans || solve(ni, nj);
            }
        }

       
        else if (curr == 4) {
            if (i + 1 < n) {
                int ni = i + 1, nj = j;
                if (!vis[ni][nj] && (grid[ni][nj] == 2 || grid[ni][nj] == 5 ||
                                     grid[ni][nj] == 6))
                    ans = ans || solve(ni, nj);
            }
            if (j + 1 < m) {
                int ni = i, nj = j + 1;
                if (!vis[ni][nj] && (grid[ni][nj] == 1 || grid[ni][nj] == 3 ||
                                     grid[ni][nj] == 5))
                    ans = ans || solve(ni, nj);
            }
        }

        
        else if (curr == 5) {
            if (i - 1 >= 0) {
                int ni = i - 1, nj = j;
                if (!vis[ni][nj] && (grid[ni][nj] == 2 || grid[ni][nj] == 3 ||
                                     grid[ni][nj] == 4))
                    ans = ans || solve(ni, nj);
            }
            if (j - 1 >= 0) {
                int ni = i, nj = j - 1;
                if (!vis[ni][nj] && (grid[ni][nj] == 1 || grid[ni][nj] == 4 ||
                                     grid[ni][nj] == 6))
                    ans = ans || solve(ni, nj);
            }
        }

        
        else if (curr == 6) {
            if (i - 1 >= 0) {
                int ni = i - 1, nj = j;
                if (!vis[ni][nj] && (grid[ni][nj] == 2 || grid[ni][nj] == 3 ||
                                     grid[ni][nj] == 4))
                    ans = ans || solve(ni, nj);
            }
            if (j + 1 < m) {
                int ni = i, nj = j + 1;
                if (!vis[ni][nj] && (grid[ni][nj] == 1 || grid[ni][nj] == 3 ||
                                     grid[ni][nj] == 5))
                    ans = ans || solve(ni, nj);
            }
        }

        return ans;
    }

    bool hasValidPath(vector<vector<int>>& g) {
        grid = g;
        n = grid.size();
        m = grid[0].size();

        vis.assign(n, vector<int>(m, 0));

        return solve(0, 0);
    }
};