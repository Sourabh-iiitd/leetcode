class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> deg(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    deg[i]+=1;
                }
            }
        }
        return deg;
    }
};