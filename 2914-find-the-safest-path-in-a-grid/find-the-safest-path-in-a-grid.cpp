class Solution {
public:
    int n,m;
    void bfs(vector<vector<int>>& grid, vector<vector<int>> &dist){
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int xdir[4]={0,-1,0,1};
        int ydir[4]={1,0,-1,0};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
           
            for(int i=0;i<4;i++){
                int nx=x+xdir[i];
                int ny=y+ydir[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny]==-1 ){
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        bfs(grid,dist);
        
        priority_queue<pair<int, pair<int, int>>> pq;
        
      
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
    
        pq.push({dist[0][0], {0, 0}});
        vis[0][0] = 1;
        
        int xdir[4] = {0, -1, 0, 1};
        int ydir[4] = {1, 0, -1, 0};
        
        while(!pq.empty()) {
            int safeness = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
          
            if(x == n-1 && y == m-1) {
                return safeness;
            }
            
            for(int i=0; i<4; i++) {
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    
                    int next_safeness = min(safeness, dist[nx][ny]);
                    pq.push({next_safeness, {nx, ny}});
                }
            }
        }
        
        return 0;

    }
};