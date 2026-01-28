class Solution {
public:
    int dp[21][2001];
    int OFFSET = 1000;

    int helper(vector<int>& nums, int idx,int sm,int target){
        if(idx==nums.size()){
            if(sm==target) return 1;
            else return 0;
        }
        if(dp[idx][sm+ OFFSET]!=-1) return dp[idx][sm+ OFFSET];
        int plus=helper(nums,idx+1,sm+nums[idx],target);
        int minus=helper(nums,idx+1,sm-nums[idx],target);
        return dp[idx][sm+ OFFSET]= plus+minus ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        memset(dp,-1,sizeof(dp));
        return helper(nums,0,0,target);

    }
};