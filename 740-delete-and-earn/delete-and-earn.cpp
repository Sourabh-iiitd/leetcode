class Solution {
public:
    int dp[10001];

    int rob(vector<int>& points, int i) {
        if (i >= points.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int pick = points[i] + rob(points, i + 2);
        int skip = rob(points, i + 1);

        return dp[i] = max(pick, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        vector<int> points(10001, 0);

        for (int x : nums) {
            points[x] += x;
        }

        memset(dp, -1, sizeof(dp));
        return rob(points, 0);
    }
};
