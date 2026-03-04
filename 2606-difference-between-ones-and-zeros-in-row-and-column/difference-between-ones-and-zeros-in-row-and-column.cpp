class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector <int> rowso(n,0);
        vector <int> colso(m,0);

        vector<vector<int>> ans(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    rowso[i]++;
                    colso[j]++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int pl=rowso[i]+colso[j];
                int mn=(n-rowso[i])+(m-colso[j]);
                ans[i][j]=pl-mn;
            }
        }
        return ans;

    }
};