class Solution {
public:
    // vector<vector<int>> grid;
    int n;
    int m;
    bool bfs(int i, int j,vector<vector<int>>& grid){
        grid[i][j]=1;
        queue<pair<int,int>> q;;
        q.push({i,j});

        int xdir[4]={-1,0,1,0};
        int ydir[4]={0,1,0,-1};
        bool isClosed = true;

        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;

            q.pop();
            if (x==0 || x==n-1 || y==0 || y==m-1) {
                isClosed=false;
            }
            for(int i=0;i<4;i++){
                int nx= x+ xdir[i];
                int ny= y+ ydir[i];
                

                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!=1){
                    q.push({nx,ny});
                    grid[nx][ny]=1;
                }
            }

            

        }
        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        this->n=grid.size();
        this->m=grid[0].size();
      
        

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    if (bfs(i, j,grid)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};