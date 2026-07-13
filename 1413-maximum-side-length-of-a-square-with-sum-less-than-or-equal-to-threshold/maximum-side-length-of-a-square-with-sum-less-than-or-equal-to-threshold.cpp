class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();


        vector<vector<int>> pref(n+1, vector<int>(m+1,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pref[i+1][j+1]= pref[i][j+1] + pref[i+1][j] - pref[i][j] + mat[i][j];
            }
        }

        int low=0;
        int high=min(m,n);

        int ans=INT_MIN;

        while(low<=high){
            int mid=low + (high-low)/2;
            bool valid=false;
            for (int r = mid; r <= n; r++) {
                for (int c = mid; c <= m; c++) {
                   
                    int r1 = r - mid;
                    int c1 = c - mid;
                    
                  
                    int current_sum = pref[r][c] - pref[r1][c] - pref[r][c1] + pref[r1][c1];
                    
                    if (current_sum <= threshold) {
                        valid = true;
                        break; 
                    }
                }
                if (valid) break;
            }

            if(valid){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }

        return ans==INT_MIN? 0 : ans;
    }
};