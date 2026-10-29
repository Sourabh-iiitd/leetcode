class Solution {
public:
    int xdir[4]={-1,1,0,0};
    int ydir[4]={0,0,-1,1};
    int n,m;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n=maze.size();
        m=maze[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<int,int>> q;

        int ex=entrance[0];
        int ey=entrance[1];

        q.push({ex,ey});
        vis[ex][ey]=1;
        int ans=INT_MAX;
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;

            q.pop();

            if((x!=ex || y!=ey) && (x==0 || x==n-1 || y==0 || y==m-1)){
                return vis[x][y]-1;  
            }

            for(int i=0;i<4;i++){
                int nx= x+xdir[i];
                int ny= y+ydir[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny]==0 && maze[nx][ny]!='+'){
                    q.push({nx,ny});
                    vis[nx][ny]=vis[x][y]+1;
                }
            }
        }


        return -1;
    }
};