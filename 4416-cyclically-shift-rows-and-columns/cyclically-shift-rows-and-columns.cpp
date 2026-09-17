class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> ans(n, vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                int newCol = (j - rowShift[i] % n + n) % n;
                int newRow = (i - colShift[newCol] % n + n) % n;

                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};

