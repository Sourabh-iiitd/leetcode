class Solution {
public:
    vector<int>del_row={-1,1,0,0};
    vector<int>del_col={0,0,-1,1};
    int m, n;
    
    bool helper(int mid,vector<vector<int>>&vis,vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        q.push({0,0});
        int tm=mid;
        vector<vector<int>>visited(m,vector<int>(n,-1));
        if(vis[0][0] <= tm && vis[0][0] != -1) return false;
        visited[0][0] = tm;

        while(!q.empty()){
            auto[row,col] = q.front();
            q.pop();
            int curr_time = visited[row][col];

            for(int k=0;k<4;k++){
                int nei_row = row + del_row[k];
                int nei_col = col + del_col[k];
                if(nei_row >= 0 && nei_col >= 0 && nei_row < m && nei_col < n){
                    if(grid[nei_row][nei_col] == 0 && visited[nei_row][nei_col] == -1){
                        int next_time = curr_time + 1;

                        if(vis[nei_row][nei_col] == -1 || vis[nei_row][nei_col] > next_time || 
                          (nei_row == m-1 && nei_col == n-1 && vis[nei_row][nei_col] == next_time)){
                            visited[nei_row][nei_col] = next_time;
                            q.push({nei_row, nei_col});
                            if(nei_row == m-1 && nei_col == n-1) return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            auto[row,col]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nei_row=row+del_row[k];
                int nei_col=col+del_col[k];

                if(nei_row>=0 && nei_col>=0 && nei_row<m && nei_col<n){
                    if(vis[nei_row][nei_col]==-1){
                        if(grid[nei_row][nei_col]==0){
                            vis[nei_row][nei_col]=1+vis[row][col];
                            q.push({nei_row,nei_col});
                        }
                    }
                }
            }
        }

        int right=vis[m-1][n-1];
        int left=0;
        if(right==-1) right=1e9;
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(helper(mid,vis,grid)){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans >= 1e8 ? (int)1e9 : ans;
    }
};