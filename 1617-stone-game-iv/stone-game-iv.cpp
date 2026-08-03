class Solution {
public:
    int n;
    int dp[100001];
    bool solve(int i){
        if(i>=n) return false;
        if(dp[i]!=-1) return dp[i];

        bool res=false;
        for(int x=1; i+x*x<=n; x++){
            res=res||!solve(i+x*x);
        }
        return dp[i]=res;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        this->n=n;
        return solve(0);
    }
};