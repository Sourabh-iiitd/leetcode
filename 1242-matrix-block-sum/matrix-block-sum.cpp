class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> pref(n+1, vector<int> (m+1,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pref[i+1][j+1]= pref[i][j+1]+ pref[i+1][j] - pref[i][j] + mat[i][j];
            }
        
        }
        vector<vector<int>> ans (n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int fr1= (i-k<0) ? 0 : i-k;
                int fc1=(j-k<0) ? 0 : j-k;
                int fr2= (i+k>=n) ? n-1: i+k;
                int fc2=(j+k>=m) ? m-1 : j+k;
                ans[i][j] = pref[fr2 + 1][fc2 + 1] - pref[fr1][fc2 + 1] - pref[fr2 + 1][fc1] + pref[fr1][fc1];
            }
        }
        return ans;
    }
};