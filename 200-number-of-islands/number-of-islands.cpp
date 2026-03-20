class Solution {
public:
    void bfs(int i, int j,vector<vector<char>>& grid, vector<vector<int>> &visited ){
        
        visited[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int xdrr[4]={-1,0,1,0};
        int ydrr[4]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int rn=r+xdrr[i];
                int yn=c+ydrr[i];
                if(rn >= 0 && yn >= 0 && rn < grid.size() && yn < grid[0].size() 
   && !visited[rn][yn] && grid[rn][yn] == '1') {
    
                    visited[rn][yn] = 1;
                    q.push({rn, yn});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char s=grid[i][j];
                
                if(!visited[i][j] && s=='1'){
                    bfs(i,j,grid,visited);
                    ans++;
                }
            }
        }

        return ans;

    }
};