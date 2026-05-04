class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        vector<pair<int, int>> valid;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            if (i >= val) {
                valid.push_back({i - val, val});
            }
        }

        sort(valid.begin(), valid.end());

        vector<int> lis;

        for (auto [diff, val] : valid) {
            auto it = lower_bound(lis.begin(), lis.end(), val);

            if (it == lis.end()) {
                lis.push_back(val);
            } else {
                *it = val;
            }
        }

        return lis.size();
    }
};