class Solution {
public:
    int n,m;
    const int MOD = 1e9 + 7;
    int memo[1005][1005][2];
    int solve(int i, int j,int dir,vector<vector<int>>& grid){
        if(i>=n || j>=m || i<0 || j<0) return 0;
        if(i== n-1 && j==m-1){
            return 1;
        }
        if(memo[i][j][dir]!=-1) return memo[i][j][dir];

        int curr=grid[i][j];

        // left;
        int ans=0;
       
        if(curr==0){
            if(i+1<n) ans=(ans+solve(i+1,j,1,grid))%MOD;
            if(j+1<m) ans=(ans+solve(i,j+1,0,grid))%MOD;
        }
        if(curr==1){
            if(dir==0) ans=solve(i+1,j, 1,grid);
            else ans=solve(i,j+1, 0,grid);
        }
        
        return memo[i][j][dir]=ans;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(memo, -1, sizeof(memo));
        return solve(0,0,0,grid);
    }
};