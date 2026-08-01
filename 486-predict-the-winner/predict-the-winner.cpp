class Solution {
    int memo[21][21];

    int helper(vector<int>& nums, int start, int end) {
        if (start==end) {
            return nums[start];
        }

        if (memo[start][end] != -1) {
            return memo[start][end];
        }

       
        int pickStart = nums[start] - helper(nums, start + 1, end);
        
       
        int pickEnd = nums[end] - helper(nums, start, end - 1);

       
        return memo[start][end] = max(pickStart, pickEnd);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return helper(nums, 0, nums.size() - 1) >= 0;
    }
};