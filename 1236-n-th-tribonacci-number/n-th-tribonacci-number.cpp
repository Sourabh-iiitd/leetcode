class Solution {
public:
    int sourabh(int n, vector<int> &dp){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=sourabh(n-3,dp)+sourabh(n-2,dp)+sourabh(n-1,dp);
    }
    
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return sourabh(n,dp);
    }
};