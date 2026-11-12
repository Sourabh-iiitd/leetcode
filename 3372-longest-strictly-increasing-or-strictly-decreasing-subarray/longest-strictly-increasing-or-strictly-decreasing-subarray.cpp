class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return 1;
        int ans=INT_MIN;
        int cnt1=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]) {
                cnt1++;
            }
            else cnt1=1;
            ans=max(cnt1,ans);
        }
        
        cnt1=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) {
                cnt1++;
            }
            else cnt1=1;
            ans=max(cnt1,ans);
        }
        return ans;
    }
};