class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int st = 0;
        int end = n - 1;

        // 1. Find longest non-decreasing prefix
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] <= arr[i + 1]) {
                st = i + 1;
            } else {
                break;
            }
        }

        // If whole array is sorted, remove 0 elements
        if (st == n - 1) return 0;

        // 2. Find longest non-decreasing suffix
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] >= arr[i - 1]) {
                end = i - 1; // Correct index for suffix start
            } else {
                break;
            }
        }

        // 3. Minimum elements to remove (deleting either suffix or prefix entirely)
        int ans = min(n - 1 - st, end);

        // 4. Merge prefix and suffix using two pointers
        int i = 0;
        int j = end;

        while (i <= st && j < n) {
            if (arr[i] <= arr[j]) {
                ans = min(ans, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }
};