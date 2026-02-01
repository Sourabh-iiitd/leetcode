class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        vector<int> left(n + 1, 1);
        vector<int> right(n + 1, 1);
        
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1]) {
                left[i + 1] = left[i] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                right[i + 1] = right[i + 2] + 1;
            }
        }

        for (int i = 1; i <= n - 1; i++) {

            int val = nums[i - 1];

            int prev = 1e9;

            if (i >= 2) {
                prev = nums[i - 2];
            }

            maxi = max(maxi, right[i] + 1);
            maxi = max(maxi, left[i] + 1);

            int next = nums[i];

            if (next >= prev) {

                maxi = max(maxi, left[i - 1] + 1 + right[i + 1]);
            }
        }

        return min(maxi, n);
    }
};