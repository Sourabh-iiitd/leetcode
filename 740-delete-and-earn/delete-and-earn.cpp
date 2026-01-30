class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& points, int i) {
        if (i >= points.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int pick = points[i] + rob(points, i + 2);
        int skip = rob(points, i + 1);

        return dp[i] = max(pick, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> points(maxVal + 1, 0);
        for (int x : nums) {
            points[x] += x;
        }

        dp.assign(maxVal + 1, -1);
        return rob(points, 0);
    }
};
