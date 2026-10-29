class Solution {
public:
    int xdir[4]={-1,1,0,0};
    int ydir[4]={0,0,-1,1};
    int n,m;
    bool bfs(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        bool isClosed = true;

        vis[i][j]=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;

            q.pop();
            if (x==0 || x==n-1 || y==0 || y==m-1) {
                isClosed=false;
            }
            for(int idx=0;idx<4;idx++){
                int nx=x+ xdir[idx];
                int ny=y+ ydir[idx];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0 && vis[nx][ny]==0){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                    
                }
            }
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    if(bfs(i,j,grid,vis)) ans++;
                }
            }
        }
        return ans;

    }
};