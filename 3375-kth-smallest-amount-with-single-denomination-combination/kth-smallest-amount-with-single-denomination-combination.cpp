class Solution {
    
    vector<int> coins;
    int n;
    
    long long CountSmaller (long long x) {
        long long ans = 0;
        
        for (int mask = 1; mask < (1 << n); mask ++) {
            long long lcm = 0, cnt = 0;
            for (int i = 0; i < n; i ++)
                if (mask&(1 << i)) {
                    cnt ++;
                    
                    if (lcm == 0) lcm = coins[i];
                    else lcm = lcm*coins[i]/__gcd(lcm, (long long)coins[i]);
                }
            
            if (cnt % 2 == 0) ans -= x/lcm;
            else ans += x/lcm;
        }
        return ans;
    }
    
public:
    long long findKthSmallest(vector<int>& c, int k) {
        coins = c;
        n = coins.size();
        
        long long l = 1, r = 1e18;
        while (l < r) {
            long long m = (l+r) >> 1;
            
            if (CountSmaller(m) >= k) r = m;
            else l = m + 1;
        }
        return l;
    }
};