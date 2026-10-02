class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        vector<int> pref(n,0),suff(n,0);
        pref[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pref[i]=min(nums[i],pref[i-1]);
            suff[n-i-1]=min(nums[n-i-1],suff[n-i]);
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>pref[i-1] && nums[i]>suff[i+1]) ans=min(ans,pref[i-1]+nums[i]+suff[i+1]);
        }
        return ans==INT_MAX?-1:ans;
    }
};