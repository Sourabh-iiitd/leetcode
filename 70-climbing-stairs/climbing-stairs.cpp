class Solution {
public:
    vector<int> dp;
    int climb(int n) {
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= climb(n-1)+climb(n-2);

    }
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return climb(n);
    }
};