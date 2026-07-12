class Solution {
public:
    vector<vector<int>> dp;

    int ways(vector<int> &ans, int amt, int idx) {
        if (amt == 0) return 1;
        if (amt < 0 || idx == ans.size()) return 0;

        if (dp[amt][idx] != -1)
            return dp[amt][idx];

        int inc = ways(ans, amt - ans[idx], idx);
        int exc = ways(ans, amt, idx + 1);

        return dp[amt][idx] = inc + exc;
    }

    vector<int> findCoins(vector<int>& numWays) {
        vector<int> ans;

        for (int i = 0; i < numWays.size(); i++) {
            int amt = i + 1;

            dp.assign(amt + 1, vector<int>(ans.size() + 1, -1));
            int wy = ways(ans, amt, 0);

            if (wy < numWays[i]) {
                ans.push_back(amt);

                dp.assign(amt + 1, vector<int>(ans.size() + 1, -1));
                wy = ways(ans, amt, 0);
            }

            if (wy != numWays[i])
                return {};
        }

        return ans;
    }
};