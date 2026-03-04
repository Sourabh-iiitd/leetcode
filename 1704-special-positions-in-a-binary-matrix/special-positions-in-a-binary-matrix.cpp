class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_map<int,int>mppi;
        unordered_map<int,int>mppj;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    mppi[i]++;
                    mppj[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    if(mppi[i]==1 && mppj[j]==1) ans++;
                }
            }
        }
        return ans;

    }
};