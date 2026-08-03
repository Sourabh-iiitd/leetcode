class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix;

    int solve(int l, int r, vector<int>& stones) {
        if (l == r) return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

       
        int sum = prefix[r + 1] - prefix[l];

      
        int a = (sum - stones[l]) - solve(l + 1, r, stones);

       
        int b = (sum - stones[r]) - solve(l, r - 1, stones);

        return dp[l][r] = max(a, b);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        dp.assign(n, vector<int>(n, -1));

        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        return solve(0, n - 1, stones);
    }
};