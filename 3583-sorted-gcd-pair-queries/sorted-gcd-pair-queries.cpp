class Solution {
    using ll = long long;
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max = ranges::max(nums);
        vector<int> freq(max + 1, 0);
        vector<ll> gcdd(max + 1, 0);
        
        for (const int num : nums) {
            freq[num]++;
        }
        
       
        for (int i = max; i > 0; i--) {
            ll sm = 0;
            ll extra = 0;
            for (int j = i; j <= max; j += i) {
                sm += freq[j];
                extra += gcdd[j];
            }
            gcdd[i] = sm * (sm - 1) / 2 - extra;
        }
        
       
        partial_sum(gcdd.begin() + 1, gcdd.end(), gcdd.begin() + 1);
        
    
        vector<int> res(queries.size());
        for (size_t i = 0; i < queries.size(); i++) {
            res[i] = ranges::upper_bound(gcdd, queries[i]) - gcdd.begin();
        }
            
        return res;
    }
};