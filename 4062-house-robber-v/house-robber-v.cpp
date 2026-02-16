class Solution {
public:
   
    long long memo[100005][2];

    long long solve(vector<int>& nums, vector<int>& colors, int i, bool prev_robbed) {
        if (i == nums.size()) return 0;
        if (memo[i][prev_robbed] != -1) return memo[i][prev_robbed];

       
        long long res = solve(nums, colors, i + 1, false);

       
        if (!prev_robbed || colors[i] != colors[i - 1]) {
            res = max(res, (long long)nums[i] + solve(nums, colors, i + 1, true));
        }

        return memo[i][prev_robbed] = res;
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            memo[i][0] = memo[i][1] = -1;
        }
        return solve(nums, colors, 0, false);
    }
};