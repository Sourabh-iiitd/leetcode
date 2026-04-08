class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        for (int i = 0; i < queries.size(); i++) {
            int li = queries[i][0];
            int ri = queries[i][1];
            int ki = queries[i][2];
            int vi = queries[i][3];

            const int MOD = 1e9 + 7;
            int idx = li;
            while (idx <= ri) {
                nums[idx] = (1LL* nums[idx] * vi) %MOD;
                idx += ki;
            }
        }
        int xr = 0;
        for (auto i : nums) {
            xr ^= i;
        }
        return xr ;
    }
};