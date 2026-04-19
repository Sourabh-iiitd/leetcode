class Solution {
public:    
    int dp[32][2][2];

    int solve(string &s, int idx, int tight, int prev){
        if(idx == s.size()) return 1;

        if(dp[idx][tight][prev] != -1) 
            return dp[idx][tight][prev];

        int res = 0;
        int limit = (tight ? s[idx]-'0' : 1);

        for(int bit = 0; bit <= limit; bit++){
            if(prev == 1 && bit == 1) continue;

            int newTight = tight && (bit == limit);

            res += solve(s, idx+1, newTight, bit);
        }

        return dp[idx][tight][prev] = res;
    }

    int findIntegers(int n) {
        string s = bitset<32>(n).to_string();
        s = s.substr(s.find('1'));

        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 1, 0);
    }
};