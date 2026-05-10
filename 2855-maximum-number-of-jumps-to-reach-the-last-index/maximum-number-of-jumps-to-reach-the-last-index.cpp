class Solution {
public:

    vector<int> dp;

    int helper(int i, vector<int>& nums, int target){

        if(i == nums.size()-1) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = -1e9;

        for(int j=i+1; j<nums.size(); j++){

            if(abs(nums[j] - nums[i]) <= target){

                ans = max(ans, 1 + helper(j, nums, target));
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();

        dp.resize(n, -1);

        int ans = helper(0, nums, target);

        return ans < 0 ? -1 : ans;
    }
};