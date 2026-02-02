class Solution {
    int dp[101];
public:

    int helper(string s, int idx){
        if(idx==s.size()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        char curr= s[idx];
        if(curr=='0') return 0;
        int take=0;
        //for one
        take=helper(s,idx+1);

        //for two
        if(idx+1<s.size()){
            int num=(s[idx]-'0')*10+(s[idx+1]-'0');
            if (num >= 10 && num <= 26) {
                take+=helper(s,idx+2);
            }
        }
        
       
        return dp[idx]=take;

    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return helper(s,0);
    }
};