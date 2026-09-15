class Solution {
public:
    bool isPal(string &s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int solve (int i, string &s, int k , vector<int> &dp){
        if(i>= s.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans=solve(i+1, s, k, dp);

        if(i+k<= s.size() && isPal(s,i,i+k-1)){
            ans=max(ans, 1+solve(i+k, s,k,dp));
        }

        if(i+k+1<= s.size() && isPal(s,i,i+k)){
            ans=max(ans, 1+solve(i+k+1, s,k,dp));
        }
        return dp[i]=ans;
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0, s,k,dp);
    }
};