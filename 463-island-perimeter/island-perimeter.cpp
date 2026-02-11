class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        
      
        bool found = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    visited[i][j] = 1;
                    found = true;
                    break; 
                }
            }
            if(found) break;
        }
        
        if(!found) return 0; 
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                
                
                if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= m || grid[nrow][ncol] == 0) {
                    ans++;
                }
                
                else if(visited[nrow][ncol] == 0) {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        return ans;
    }
};