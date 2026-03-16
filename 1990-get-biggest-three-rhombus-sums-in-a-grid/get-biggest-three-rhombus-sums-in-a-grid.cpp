class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        set<int> st;   
        
        int dx[4] = {1,1,-1,-1};
        int dy[4] = {1,-1,-1,1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                st.insert(grid[i][j]);
                
                for(int k=1;;k++){
                    
                    if(i-k<0 || i+k>=n || j-k<0 || j+k>=m)
                        break;
                    
                    int x = i-k;
                    int y = j;
                    int sum = 0;
                    
                    for(int d=0; d<4; d++){
                        for(int step=0; step<k; step++){
                            sum += grid[x][y];
                            x += dx[d];
                            y += dy[d];
                        }
                    }
                    
                    st.insert(sum);
                }
            }
        }
        
        vector<int> ans;
        
        for(auto it = st.rbegin(); it != st.rend() && ans.size()<3; it++){
            ans.push_back(*it);
        }
        
        return ans;
    }
};