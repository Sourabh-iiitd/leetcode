class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        long long currsm=0;
        int l=0;
        unordered_map<int,int> mpp;
        for(int r=0;r<nums.size();r++){
            currsm+=nums[r];
            mpp[nums[r]]++;

            if(r-l+1>k){
                currsm-=nums[l];
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if(r-l+1==k && mpp.size()==k){
                ans=max(ans, currsm);
            }
        }
        return ans;
    }
};