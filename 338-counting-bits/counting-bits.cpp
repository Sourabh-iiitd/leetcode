class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(1, 0);
        int i = 0;
        while (++i <= n)
            dp.push_back(dp[i & (i - 1)] + 1);
        return dp;
    }
};