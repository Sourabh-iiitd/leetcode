class Solution {
public:
    int n,m;

    bool dfs(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<int>>& vis){
        vis[i][j]=1;
        bool isSubIsland=true;

        if(grid1[i][j]==0){
            isSubIsland=false;
        }

        int xdir[4]={-1,0,1,0};
        int ydir[4]={0,1,0,-1};

        for(int k=0;k<4;k++){
            int nx=i+xdir[k];
            int ny=j+ydir[k];

            if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny]==0 && grid2[nx][ny]==1){
                bool nextCell=dfs(nx,ny,grid1,grid2,vis);
                isSubIsland=isSubIsland && nextCell;
            }
        }

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1,vector<vector<int>>& grid2){
        n=grid2.size();
        m=grid2[0].size();
        int ans=0;

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid2[i][j]==1){
                    if(dfs(i,j,grid1,grid2,vis)){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};