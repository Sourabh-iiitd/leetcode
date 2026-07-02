class Solution {
public:
    int n,m;
    vector<vector<int>> best;   // <-- Added

    bool path(int i, int j, vector<vector<int>>& grid, int health,
              vector<vector<int>> &vis){

        if(health<=0) return false;

        if(i==n-1 && j==m-1) return true;

        
        if(best[i][j] >= health) return false;
        best[i][j] = health;

        int xdir[4]={-1,0,1,0};
        int ydir[4]={0,1,0,-1};

        vis[i][j]=1;

        bool ans=false;

        for(int k=0;k<4;k++){
            int nx=i+xdir[k];
            int ny=j+ydir[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                ans = ans || path(nx,ny,grid,
                                  health-grid[nx][ny],vis);
            }
        }

        vis[i][j]=0;
        return ans;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        best.assign(n, vector<int>(m,-1));  

        return path(0,0,grid,health-grid[0][0],vis);
    }
};