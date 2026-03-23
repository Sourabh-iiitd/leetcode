class Solution {
public:
    void dfs (int i, int j, vector<vector<char>>& grid,vector<vector<int>> &vis ){
        vis[i][j]=1;
        int xdirr[4]={-1,0,1,0};
        int ydirr[4]={0,1,0,-1};

        for(int d=0;d<4;d++){
            int nxdir=i+xdirr[d];
            int nydir=j+ydirr[d];
            if(nxdir>=0 && nydir>=0 && nxdir<grid.size() && nydir<grid[0].size() && grid[nxdir][nydir]=='1' && vis[nxdir][nydir]==0){
                dfs(nxdir, nydir, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    

    }
};