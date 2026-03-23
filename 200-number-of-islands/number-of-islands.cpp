class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '1' && !vis[i][j]) {
                    ans++; // new island found

                    queue<pair<int,int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;

                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if(nx >= 0 && ny >= 0 && nx < n && ny < m &&
                               grid[nx][ny] == '1' && !vis[nx][ny]) {
                                
                                vis[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};