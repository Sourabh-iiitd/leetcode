class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, long long m) {
        const long long MOD = 1e9 + 7;

        int n = value.size();

        auto check = [&](long long x) {
            long long cnt = 0;
            for (int i = 0; i < n; i++) {
                if (value[i] < x) continue;
                cnt += (value[i] - x) / decay[i] + 1;
            }
            return cnt;
        };

        long long lo = 0, hi = 1e9;
        long long best = 0;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (check(mid) >= m) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        auto power = [&](long long a, long long b) {
            long long ans = 1;
            a %= MOD;

            while (b) {
                if (b & 1) ans = (ans * a) % MOD;
                a = (a * a) % MOD;
                b >>= 1;
            }

            return ans;
        };

        long long inv2 = power(2, MOD - 2);

        long long taken = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {

            if (value[i] < best + 1) continue;

            long long k = (value[i] - (best + 1)) / decay[i] + 1;
            taken += k;

            long long first = value[i];
            long long last = value[i] - (k - 1) * 1LL * decay[i];

            first %= MOD;
            last %= MOD;

            long long sum = (first + last) % MOD;
            sum = (sum * (k % MOD)) % MOD;
            sum = (sum * inv2) % MOD;

            ans = (ans + sum) % MOD;
        }

        ans = (ans + (best % MOD) * ((m - taken) % MOD)) % MOD;

        return ans;
    }
};