class Solution {
public:
    int sm(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n = n / 10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = sm(nums[i]);
            mini = min(nums[i], mini);
        }

        return mini;
    }
};