class Solution {
public:
    int m,n,k;
    vector<vector<int>> g;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int cost){
        if(cost > k) return -1e9;
        if(i==n-1 && j==m-1){
            int curr = g[i][j];
            int c = (curr==1 || curr==2);
            if(cost + c <= k){
                return curr;
            }
            else{
                return -1e9;
            }
        }

        if(dp[i][j][cost] != -1) return dp[i][j][cost];

        int curr = g[i][j];
        int c = (curr==1 || curr==2);

        int ans = -1e9;

        if(i+1<n){
            ans = max(ans, curr + solve(i+1,j,cost+c));
        }
        if(j+1<m){
            ans = max(ans, curr + solve(i,j+1,cost+c));
        }

        return dp[i][j][cost] = ans;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        this->k = k;
        this->g = grid;

     
        dp.assign(n, vector<vector<int>>(m, vector<int>(k+1, -1)));

        int ans = solve(0,0,0);
        return (ans < 0 ? -1 : ans);
    }
};