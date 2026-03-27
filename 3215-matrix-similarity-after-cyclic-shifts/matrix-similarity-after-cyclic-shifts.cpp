class Solution {
public:
    vector<int> shiftRight(vector<int>& row, int k) {
        int n = row.size();
        vector<int> temp(n);
        k = k % n;

        for(int i = 0; i < n; i++) {
            temp[(i + k) % n] = row[i];
        }
        return temp;
    }

    vector<int> shiftLeft(vector<int>& row, int k) {
        int n = row.size();
        vector<int> temp(n);
        k = k % n;

        for(int i = 0; i < n; i++) {
            temp[i] = row[(i + k) % n];
        }
        return temp;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> chk = mat;
        int n = mat.size();

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                mat[i] = shiftLeft(mat[i], k);
            } else {
                mat[i] = shiftRight(mat[i], k);
            }
        }

        return mat == chk;
    }
};