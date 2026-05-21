class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<pair<int,int>>> v(201);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] > 0) v[matrix[i][j]].push_back({i, j});
            }
        }
        int cnt = 0;

        for(int num = 1; num <= 200; num++) {
            for(auto it : v[num]) {
                int x = it.first;
                int y = it.second;
                bool flag = true;
                for(int j = num + 1; j < 201 && flag; j++) {
                    for(auto &[r, c] : v[j]) {
                     
                        if (r < x - num) continue;
                        
                   
                        if (r > x + num) break;

                        int newx = abs(r - x);
                        int newy = abs(c - y);
                        
                        
                        if(newx <= num && newy <= num) { 
                            if(newx == num && newy == num) {
                                continue;
                            }
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag) cnt++;
            }
        }
        return cnt;
    }
};