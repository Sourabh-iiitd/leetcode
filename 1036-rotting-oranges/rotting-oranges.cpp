class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        int xdir[4]={-1,0,1,0};
        int ydir[4]={0,1,0,-1};
        int fresh=0;
        queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 && !vis[i][j]){
                    
                    vis[i][j]=1;
                    q.push({{i,j},0});
        
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        int t=0;
        while(!q.empty()){
                        int r=q.front().first.first;
                        int c=q.front().first.second;
                        int steps=q.front().second;
                        

                        q.pop();

                        t=max(t,steps);

                        for(int k=0;k<4;k++){
                            int rn=r+xdir[k];
                            int rc=c+ydir[k];
                            if(rn>=0 && rc>=0 && rn<grid.size() && rc<grid[0].size() && !vis[rn][rc] && grid[rn][rc]==1 ){
                                vis[rn][rc]=1;
                                q.push({{rn,rc},steps+1});
                                fresh--;
                            }
                        }
                    }
        if(fresh>0) return -1;
        return t;
    }
};