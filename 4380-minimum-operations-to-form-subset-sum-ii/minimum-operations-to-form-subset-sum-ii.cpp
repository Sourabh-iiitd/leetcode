class Solution {
public:
    int n;
    int dp[101][5005];
    vector<int> nums;

    int solve(int i, int sum) {
        if (sum == 0) return 0;
        if (i >= n) return 1e9; 
        if (dp[i][sum] != -1) return dp[i][sum];

        
        int ans = solve(i + 1, sum);

       
        int div_val = nums[i];
        int div_ops = 0;

        while (div_val > 0) {
            long long mul_val = div_val;
            int mul_ops = 0;

            while (mul_val <= sum) {
                int total_ops = div_ops + mul_ops;
                int rem = solve(i + 1, sum - mul_val);
                if (rem < 1e9) {
                    ans = min(ans, total_ops + rem);
                }
                mul_val *= 2;
                mul_ops++;
            }

            div_val /= 2;
            div_ops++;
        }

        return dp[i][sum] = ans;
    }

    int minOperations(vector<int>& nums, int sum) {
        this->nums = nums;
        this->n = nums.size();
        memset(dp, -1, sizeof(dp));
        
        int res = solve(0, sum);
        return res >= 1e9 ? -1 : res;
    }
};