class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        queue<tuple<int,int,int>> q; 

        for(auto &s : sources){
            int r = s[0], c = s[1], col = s[2];
            q.push({r, c, col});
            grid[r][c] = col;
            dist[r][c] = 0;
        }

        int xdir[4] = {-1,0,1,0};
        int ydir[4] = {0,1,0,-1};

        while(!q.empty()){
            auto [row, col, color] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + xdir[i];
                int ncol = col + ydir[i];

                if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= m) continue;

                if(dist[nrow][ncol] == INT_MAX){
                    dist[nrow][ncol] = dist[row][col] + 1;
                    grid[nrow][ncol] = color;
                    q.push({nrow, ncol, color});
                }
                else if(dist[nrow][ncol] == dist[row][col] + 1){
                    if(grid[nrow][ncol] < color){
                        grid[nrow][ncol] = color;
                        q.push({nrow, ncol, color});
                    }
                }
            }
        }

        return grid;
    }
};