class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            int distinctEvens = 0;
            int distinctOdds = 0;

            for (int j = i; j < n; j++) {
                if (seen.find(nums[j]) == seen.end()) {
                    if (nums[j] % 2 == 0)
                        distinctEvens++;
                    else
                        distinctOdds++;
                    seen.insert(nums[j]);
                }

                if (distinctEvens == distinctOdds) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};