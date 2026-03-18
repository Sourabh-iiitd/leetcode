class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> prefSumArr(n,vector<int>(m,0));
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(i==0 && j==0) 
                    prefSumArr[i][j] = grid[i][j];

                else if(i==0)
                    prefSumArr[i][j] = grid[i][j] + prefSumArr[i][j-1];

                else if(j==0)
                    prefSumArr[i][j] = grid[i][j] + prefSumArr[i-1][j];

                else
                    prefSumArr[i][j] = grid[i][j]
                                     + prefSumArr[i-1][j]
                                     + prefSumArr[i][j-1]
                                     - prefSumArr[i-1][j-1];

                if(prefSumArr[i][j] <= k) 
                    count++;
            }
        }

        return count;
    }
};