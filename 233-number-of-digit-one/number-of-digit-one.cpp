class Solution {
public:    
    int dp[12][2][12];
    int solve(string &s, int idx, int tight, int cnt ){
        if(idx==s.size()) return cnt;
        if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];

        int res=0;
        int limit= (tight==1 ? s[idx]-'0':9);
        for(int i=0;i<=limit;i++){
            int cnt1=cnt+(i==1?1:0);
            res+=solve(s, idx+1, tight && (i==limit),cnt1);
        }
        return dp[idx][tight][cnt] = res;
    }
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        string s=to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s,0,1,0);
    }
};