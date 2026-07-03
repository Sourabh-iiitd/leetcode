class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            if (num == 2) {
                ans.push_back(-1);
            } else {
                for (int i = 0; i < 31; ++i) {
                    if (((num >> (i + 1)) & 1) == 0) {
                        ans.push_back(num ^ (1 << i));
                        break;
                    }
                }
            }
        }
        return ans;
    }
};