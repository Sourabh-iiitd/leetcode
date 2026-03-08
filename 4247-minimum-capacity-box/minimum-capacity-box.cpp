class Solution {
public:
    int minimumIndex(vector<int>& nums, int itemSize) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=itemSize) ans=min(ans,nums[i]);
        }

        int idx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==ans) {
                idx=i;
                break;
            }
        }
        return idx;

    }
};