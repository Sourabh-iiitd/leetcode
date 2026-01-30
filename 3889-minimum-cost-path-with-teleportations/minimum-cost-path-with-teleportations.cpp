class Solution {
public:
//nice vdo hehehehhee
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, INT_MAX));

        dp[m-1][n-1]=0;
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi, grid[i][j]);
            }
        }

        vector<int> telecost(maxi+1, INT_MAX);

        for(int t=0 ; t<=k; t++){
            for(int i=m-1; i>=0 ; i--){
                for(int j=n-1; j>=0 ;j-- ){
                    if(i+1<m && dp[i + 1][j] != INT_MAX){
                        dp[i][j]=min(dp[i][j], dp[i+1][j]+grid[i+1][j]);
                    }
                    if(j+1<n && dp[i][j+1] != INT_MAX){
                        dp[i][j]= min(dp[i][j], grid[i][j+1]+dp[i][j+1]);
                    }
                    if(t>0){
                        dp[i][j]=min(dp[i][j], telecost[grid[i][j]]);
                    }
                }
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    telecost[grid[i][j]]=min(telecost[grid[i][j]], dp[i][j]);
                }
            }

            for(int i=1; i<telecost.size();i++){
                telecost[i]=min(telecost[i],telecost[i-1]);
            }
        }
        return dp[0][0];
    }
};