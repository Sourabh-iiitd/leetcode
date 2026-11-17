class Solution {
    int n;
    const int INF = 1e9;
    vector<vector<int>> cost;
    vector<vector<int>> memo;

    int solve(int idx, int partsLeft) {
        if (partsLeft == 0 && idx == n) return 0;
        if (partsLeft == 0 || idx >= n) return INF;
        if (memo[idx][partsLeft] != -1) return memo[idx][partsLeft];

        int ans = INF;
       
        int maxEnd = n - 2 * (partsLeft - 1) - 1;

        for (int end = idx + 1; end <= maxEnd; ++end) {
            int nextRes = solve(end + 1, partsLeft - 1);
            if (nextRes != INF) {
                ans = min(ans, cost[idx][end] + nextRes);
            }
        }

        return memo[idx][partsLeft] = ans;
    }

public:
    int minimumChanges(string s, int k) {
        n = s.size();
        cost.assign(n, vector<int>(n, INF));
        memo.assign(n + 1, vector<int>(k + 1, -1));

       
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d = 1; d < len; ++d) {
                    if (len % d != 0) continue;
                    int changes = 0;
                    for (int start = 0; start < d; ++start) {
                        int left = i + start;
                        int right = j - (d - 1 - start);
                        while (left < right) {
                            if (s[left] != s[right]) changes++;
                            left += d;
                            right -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

       
        return solve(0, k);
    }
};