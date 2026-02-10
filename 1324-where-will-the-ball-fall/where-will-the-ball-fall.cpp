class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int balls=grid[0].size();
        int rows=grid.size();
        int cols=grid[0].size();

        vector<int> ans(balls,1);

        for(int i=0;i<balls;i++){
            int c=i;
            for(int r=0;r<rows;r++){
                if(grid[r][c]==1){
                    if(c + 1 >= cols || grid[r][c + 1] == -1){
                        c = -1;
                        break;
                    }
                    c++;
                }
                else{
                    if(c - 1 < 0 || grid[r][c - 1] == 1){
                        c = -1;
                        break;
                    }
                    c--;
                }

            }
            ans[i]=c;
            
        }
        return ans;


        
    }
};