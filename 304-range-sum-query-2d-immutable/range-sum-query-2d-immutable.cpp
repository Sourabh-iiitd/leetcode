class NumMatrix {
private:
    vector<vector<int>> pref;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int r=matrix.size();
        int c=matrix[0].size();
        pref.assign(r+1, vector<int>(c+1, 0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                pref[i+1][j+1]=pref[i][j+1]+ pref[i+1][j] - pref[i][j]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pref[row2 + 1][col2 + 1] - pref[row1][col2 + 1] - pref[row2 + 1][col1] + pref[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */