class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long tsum=0;
        int n=grid.size();
        int m=grid[0].size();
        long long curr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tsum+=grid[i][j];
            }
        }
        //horixontal cuts
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                curr+=grid[i][j];
            }
            if(curr == tsum-curr) return true;
        }
        // ver cuts
        curr=0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                curr+=grid[j][i];
            }
            if(curr == tsum-curr) return true;
        }


        return false;
    }
};