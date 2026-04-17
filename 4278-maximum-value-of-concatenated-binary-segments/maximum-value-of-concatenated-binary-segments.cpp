class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        
        vector<int> idx(n);
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            bool noZeros_i = (nums0[i] == 0);
            bool noZeros_j = (nums0[j] == 0);
            
            if (noZeros_i != noZeros_j) return noZeros_i > noZeros_j;
            if (nums1[i] != nums1[j]) return nums1[i] > nums1[j];
            return nums0[i] < nums0[j];
        });

        string result = "";
        for (int i : idx) {
            for (int k = 0; k < nums1[i]; k++) {
                result += '1';
            }
            for (int k = 0; k < nums0[i]; k++) {
                result += '0';
            }
        }

        long long val = 0;
        long long mod = 1e9 + 7;
        for (char c : result) {
            val = (val * 2 + (c - '0')) % mod;
        }
        
        return val;
    }
};