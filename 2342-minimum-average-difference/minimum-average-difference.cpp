class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        long long total = 0;
        for(int x : nums)
            total += x;

        long long leftSum = 0;
        long long mini = LLONG_MAX;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            leftSum += nums[i];

            long long leftAvg = leftSum / (i + 1);

            long long rightSum = total - leftSum;
            long long rightAvg = 0;

            if(i != n - 1)
                rightAvg = rightSum / (n - i - 1);

            long long diff = abs(leftAvg - rightAvg);

            if(diff < mini) {
                mini = diff;
                ans = i;
            }
        }

        return ans;
    }
};