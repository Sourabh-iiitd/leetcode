class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> less_than(n, vector<int>(n+1,0));
        for(int j=0;j<n;j++){
            if (j > 0) {
                less_than[j] = less_than[j - 1];
            }
            for( int v=nums[j]+1; v<=n;v++){
                less_than[j][v]++;
            }
        }

        vector<vector<int>> grtr_than(n, vector<int>(n+1,0));
        for(int k=n-1;k>=0;k--){
            if(k<n-1) {
                grtr_than[k]=grtr_than[k+1];
            }
            for(int v=1; v<nums[k];v++){
                grtr_than[k][v]++;
            }
        }


        long long ans=0;
        for (int j=1; j<n-1; j++) {
            for (int k=j+1; k<n;k++) {
                if(nums[k]<nums[j]){
                    long long x= less_than[j][nums[k]];
                    long long y= grtr_than[k][nums[j]];
                    ans+= (x*y);
                }
            }
        }
        return ans;
    }
};