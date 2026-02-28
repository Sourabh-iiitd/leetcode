class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 0;

        for(int i = 1; i <= n; i++){  
            
            int num = i;
            int bits = 0;


            while(num > 0){
                bits++;
                num >>= 1;
            }

            ans = ((ans << bits) % MOD + i) % MOD;
        }

        return ans;
    }
};