class Solution {
public:
    int n;
    int dp[50001];

    int solve(int i, vector<int>& stoneValue) {
        if (i >= n) return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int stones = 0;
        int ans = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            stones += stoneValue[i + k];
            ans = max(ans, stones - solve(i + k + 1, stoneValue));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();

        for (int i = 0; i <= n; i++)
            dp[i] = INT_MIN;

        int diff = solve(0, stoneValue);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};