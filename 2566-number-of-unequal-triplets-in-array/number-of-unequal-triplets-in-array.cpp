class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int n : nums)
            mpp[n]++;
        int ans = 0, left = 0, right = nums.size();
        for (auto [n, cnt] : mpp) {
            right -= cnt;
            ans += left * cnt * right;
            left += cnt;
        }
        return ans;
    }
};