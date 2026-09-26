class Solution {
public:

    void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2) {
        if (arr1[ind1] > arr2[ind2]) {
            swap(arr1[ind1], arr2[ind2]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Step 1: Copy nums2 into the end of nums1
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }

        // Total length after combining both
        int len = m + n;

        // Step 2: Apply gap method
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                swapIfGreater(nums1, nums1, left, right);
                left++;
                right++;
            }

            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};
