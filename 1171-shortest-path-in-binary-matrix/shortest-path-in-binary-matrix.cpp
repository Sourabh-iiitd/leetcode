class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int xdis[8]={-1,-1,0,1,1,1,0,-1};
        int ydis[8]={0,1,1,1,0,-1,-1,-1};
        if(grid[0][0]==0) q.push({{0,0},1});
        else return -1;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            if(x==n-1 && y==m-1) return dis;
            for(int i=0;i<8;i++ ){
                int xn=x+xdis[i];
                int yn=y+ydis[i];
                if(xn<n && yn<m && xn>=0 && yn>=0 && grid[xn][yn]==0 ){
                    q.push({{xn,yn},dis+1});
                    grid[xn][yn] = 1; 
                }
            }

        }
        return -1;
    }
};