class Solution {
public:
    bool possible(vector<vector<int>>& grid, int mask){
        for(int i=0;i<grid.size();i++){
            bool found=false;
            for(int j=0;j<grid[0].size();j++){
                if((grid[i][j]|mask)==mask) {
                    found=true;
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }
    int minimumOR(vector<vector<int>>& grid) {
        int low=0;
        int high=(1<<17)-1;
        int ans=high;
        while(low<=high){
            int x=low+(high-low)/2;
            if(possible(grid,x)){
                ans=x;
                high=x-1;
            }
            else{
                low=x+1;
            }
        }
        return ans;
    }
    
};