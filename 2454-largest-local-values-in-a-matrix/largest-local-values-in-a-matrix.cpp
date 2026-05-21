class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
       
        int n=grid.size();

        vector<vector<int>> maxLocal(n-2,vector<int>(n-2,0));

        int idirr[8]={-1,-1,-1,0,1,1,1,0};
        int jdirr[8]={-1,0,1,1,1,0,-1,-1};

        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int num=maxLocal[i][j];
                int x=i+1;
                int y=j+1;
                int maxi=grid[x][y];
                for(int k=0;k<8;k++){
                    int nx=x+idirr[k];
                    int ny=y+jdirr[k];
                    maxi=max(maxi, grid[nx][ny]);
                }
                maxLocal[i][j]=maxi;

            }
        }
        return maxLocal;




    }
};