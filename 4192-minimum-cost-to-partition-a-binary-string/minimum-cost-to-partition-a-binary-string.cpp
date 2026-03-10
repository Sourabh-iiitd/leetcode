class Solution {
public:
    // vector<vector<long long>> dp;
    // map<pair<int, int>, long long> dp;
    long long count(int st, int end, string &s) {
        long long count = 0;
        for (int i = st; i <= end; i++) {
            if (s[i] == '1')
                count++;
        }
        return count;
    }
    long long helper(int start, int end, string &s, int encCost, int flatCost) {
        if (start > end)
            return 0;
        if (start == end) {
            if (s[start] == '1')
                return encCost;
            else
                return flatCost;
        }
        // if (dp[start][end] != -1)
        //     return dp[start][end];
        // if (dp.count({start, end}))
        //     return dp[{start, end}];
        long long ans = LLONG_MAX;
        long long curr_cost1 = LLONG_MAX;
        long long curr_cost2 = LLONG_MAX;
        long long curr_cost3 = LLONG_MAX;
        int x = count(start, end, s);
        if (x == 0) {
            curr_cost1 = flatCost;
        } else {
            curr_cost2 = 1LL * (end - start + 1) * x * encCost;
        }

        if ((end - start + 1) % 2 == 0) {
            int mid = start + (end - start) / 2;
            curr_cost3 = helper(start, mid, s, encCost, flatCost) +
                         helper(mid + 1, end, s, encCost, flatCost);
        }

        ans = min(curr_cost1, min(curr_cost2, curr_cost3));

        // return dp[start][end] = ans;
        return ans;
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        // dp.assign(n, vector<long long>(n, -1));
        // dp.clear(); 
        return helper(0, s.size() - 1, s, encCost, flatCost);
    }
};