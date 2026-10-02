class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                   for(int d=k+1;d<n;d++){
                    if(nums[i]+nums[j]+nums[k]==nums[d]) ans++;
                   }
                }
            }
        }
        return ans;
    }
};