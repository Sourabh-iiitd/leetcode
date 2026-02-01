class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        int maxi = 1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, left[i]);
            
            if (i > 0) {
                maxi = max(maxi, left[i - 1] + 1);
            }
            if (i < n - 1) {
                maxi = max(maxi, right[i + 1] + 1);
            }
            if (i > 0 && i < n - 1 && nums[i - 1] <= nums[i + 1]) {
                maxi = max(maxi, left[i - 1] + 1 + right[i + 1]);
            }
        }

        return min(maxi, n);
    }
};