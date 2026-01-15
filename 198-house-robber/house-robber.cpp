class Solution {
public:
    int robb(vector<int> &nums, int idx,vector<int> &dp){
        if (idx >= nums.size()) {
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int pick=nums[idx]+robb(nums,idx+2,dp);

        int notpick=robb(nums,idx+1,dp);
        return dp[idx]=max(pick,notpick);

    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        // int total=0;
        return robb(nums,0,dp);
        // return total; 
    }
};