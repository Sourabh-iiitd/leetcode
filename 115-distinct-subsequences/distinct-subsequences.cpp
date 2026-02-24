class Solution {
    int n, m;

    long long solve(int i, int j, string& A, string& B,
                    vector<vector<long long>>& dp) {

        if (j == m) return 1;
        if (i == n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        long long ans = 0;

        if (A[i] == B[j]) {
            long long take = solve(i + 1, j + 1, A, B, dp);
            long long notTake = solve(i + 1, j, A, B, dp);
            ans = take + notTake;
        } 
        else {
            ans = solve(i + 1, j, A, B, dp);
        }

        return dp[i][j] = ans;
    }

public:
    int numDistinct(string A, string B) {
        n = A.length();
        m = B.length();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        return solve(0, 0, A, B, dp);
    }
};