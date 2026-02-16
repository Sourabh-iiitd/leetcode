class Solution {
public:
    int dp[2501][2502];
    int solve(vector<int>& nums, int prev, int curr){
        if(curr==nums.size()) return 0;
        if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];
        int not_take=solve(nums,prev,curr+1);
        int take=0;
        if(prev==-1 || nums[prev]<nums[curr]){
            take=1+solve(nums,curr,curr+1);
        }
        return dp[prev+1][curr]=max(take,not_take);

    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,-1,0);
    }
};