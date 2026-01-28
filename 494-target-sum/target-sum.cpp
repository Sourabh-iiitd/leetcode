class Solution {
public:
    int helper(vector<int>& nums, int idx,int sm,int target){
        if(idx==nums.size()){
            if(sm==target) return 1;
            else return 0;
        }
        int plus=helper(nums,idx+1,sm+nums[idx],target);
        int minus=helper(nums,idx+1,sm-nums[idx],target);
        return plus+minus ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums,0,0,target);

    }
};