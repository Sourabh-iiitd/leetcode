class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int  i=x;
        int m=x+k-1;
        while(i<=m){
            for(int j=y;j<y+k;j++){
                int fs=grid[i][j];
                int sec=grid[m][j];
                int temp=fs;
                grid[i][j]=sec;
                grid[m][j]=temp;
            }
            i++;
            m--;
        }
        return grid;
    }
};