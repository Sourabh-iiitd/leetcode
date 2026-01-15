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
        if(nums.size()==1) return nums[0];
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        vector<int> arr1;
        vector<int>arr2;
        for(int i=0;i<nums.size()-1;i++){
            arr1.push_back(nums[i]);
        }
        for(int i=1;i<nums.size();i++){
             arr2.push_back(nums[i]);
        }
        // int total=0;
        return max(robb(arr1,0,dp1),robb(arr2,0,dp2));
        // return total; 
    }
};