class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    int solve(int i, int j , int xr,vector<vector<int>>& grid){
        if(i==n-1 && j==m-1){
            return xr^grid[i][j];
        }
        if(dp[i][j][xr]!=-1) return dp[i][j][xr];
        int curr= grid[i][j];
        int ans=INT_MAX;
        if(j+1<m) ans=min(ans, solve(i,j+1,curr^xr,grid ));
        if(i+1<n) ans=min(ans, solve(i+1,j,curr^xr,grid ));
        return dp[i][j][xr]=ans;
    }
    int minCost(vector<vector<int>>& grid) {
        this->n= grid.size();
        this->m= grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(1024, -1)));
        return solve(0,0,0,grid);
    }
};