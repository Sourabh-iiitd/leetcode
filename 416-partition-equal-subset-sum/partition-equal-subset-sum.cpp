class Solution {
public:
  
    bool helper(vector<int> & nums, int idx, int target, vector<vector<int>> &dp){
        if(target==0){
            return true;
        }
        if(idx==0){
            return nums[0]==target;
        }
  
        if(dp[idx][target] != -1) return dp[idx][target];

        bool not_take = helper(nums, idx-1, target, dp);
        bool take = false;
        
        if(nums[idx]<=target){
            take = helper(nums, idx-1, target-nums[idx], dp);
        }

        return dp[idx][target] = (take || not_take); 
    }

    bool canPartition(vector<int>& nums) {
        int s=0;
        for(int x:nums){
            s+=x;
        }
        if(s%2!=0) return false;
        else{
            int target = s/2;
            int n = nums.size();
            
           
            vector<vector<int>> dp(n, vector<int>(target + 1, -1));
      
            return helper(nums, n-1, target, dp);
        }
    }
};