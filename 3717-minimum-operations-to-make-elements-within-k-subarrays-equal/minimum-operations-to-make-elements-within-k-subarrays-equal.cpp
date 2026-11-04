class Solution {
public:
    int n;
    vector<vector<long long>> memo;
    vector<long long> cst;

    long long helper(int idx, int x, int k, const vector<int>& nums) {
        if (k == 0) return 0;
        if (idx >= n || (n - idx) < (long long)k * x) return LLONG_MAX;
        if (memo[idx][k] != -1) return memo[idx][k];

        long long take = LLONG_MAX;
        if (n - idx >= x) {
            long long next_cost = helper(idx + x, x, k - 1, nums);
            if (next_cost != LLONG_MAX) {
                take = cst[idx] + next_cost;
            }
        }

        long long nottake = helper(idx + 1, x, k, nums);
        return memo[idx][k] = min(nottake, take);
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        n = nums.size();
        cst.resize(n - x + 1);

        multiset<long long> left, right;
        long long sum_left = 0, sum_right = 0;

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                sum_left -= *it;
                sum_right += *it;
                right.insert(*it);
                left.erase(it);
            }
            while (left.size() < right.size()) {
                auto it = right.begin();
                sum_right -= *it;
                sum_left += *it;
                left.insert(*it);
                right.erase(it);
            }
        };

        auto add = [&](long long val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sum_left += val;
            } else {
                right.insert(val);
                sum_right += val;
            }
            balance();
        };

        auto remove = [&](long long val) {
            auto it_left = left.find(val);
            if (it_left != left.end()) {
                sum_left -= *it_left;
                left.erase(it_left);
            } else {
                auto it_right = right.find(val);
                if (it_right != right.end()) {
                    sum_right -= *it_right;
                    right.erase(it_right);
                }
            }
            balance();
        };

        // Initialize first window [0, x-1]
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }
        long long median = *left.rbegin();
        cst[0] = (median * left.size() - sum_left) + (sum_right - median * right.size());

        // Slide window
        for (int i = 1; i + x <= n; i++) {
            remove(nums[i - 1]);
            add(nums[i + x - 1]);
            median = *left.rbegin();
            cst[i] = (median * left.size() - sum_left) + (sum_right - median * right.size());
        }

        memo.assign(n + 1, vector<long long>(k + 1, -1));
        return helper(0, x, k, nums);
    }
};