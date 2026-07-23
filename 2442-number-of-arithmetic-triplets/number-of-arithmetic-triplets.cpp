class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int i = 0, j = 1, k = 2;
        int count = 0;
        int n = nums.size();
        while (i < n - 2 && j < n - 1 && k < n) {
            int d1 = nums[j] - nums[i];
            int d2 = nums[k] - nums[j];

            if (d1 == diff && d2 == diff) {
                count++;
                i++;
                j++;
                k++;
            } else if (d1 < diff) {
                j++;
            } else if (d1 > diff) {
                i++;
            } else if (d2 < diff) {
                k++;
            } else if (d2 > diff) {
                j++;
            }
        }
        return count;
    }
};