class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long MOD = 1000000007;
        int n = s.size();

        vector<int> prefix(n + 1, 0);
        vector<long long> prefix_x(n + 1, 0);
        vector<long long> pow10(n + 1, 1);
        
      
        vector<int> prefix_count(n + 1, 0); 

        int sm = 0;
        int nz_count = 0; 
        long long current_x = 0;

        for (int i = 0; i < n; i++) {
            pow10[i + 1] = (pow10[i] * 10) % MOD;
            
            if (s[i] != '0') {
                sm += (s[i] - '0');
                nz_count++; 
                current_x = (current_x * 10 + (s[i] - '0')) % MOD;
            }
            
            prefix[i + 1] = sm;
            prefix_count[i + 1] = nz_count; 
            prefix_x[i + 1] = current_x;
        }

        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            long long sum = prefix[r + 1] - prefix[l];
            int non_zero_count = prefix_count[r + 1] - prefix_count[l];

            long long x = (prefix_x[r + 1] - (prefix_x[l] * pow10[non_zero_count]) % MOD + MOD) % MOD;

            ans[i] = (x * sum) % MOD;
        }

        return ans;
    }
};