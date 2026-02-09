class Solution {
public:

    int dp[40001][3];

    int solve(vector<int>& nums, int i, int rem){

        if(i == nums.size()){
            return (rem == 0) ? 0 : -1e9;
        }

        if(dp[i][rem] != -1) return dp[i][rem];

   
        int nk = solve(nums, i + 1, rem);

  
        int tk = nums[i] + solve(nums, i + 1, (rem + nums[i]) % 3);

        return dp[i][rem] = max(tk, nk);
    }

    int maxSumDivThree(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0);
    }
};
