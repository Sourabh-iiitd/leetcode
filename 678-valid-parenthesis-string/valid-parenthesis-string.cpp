class Solution {
public:
    bool helper(string s,int idx, int c,vector<vector<int>> &dp){
        if(c<0) return false;
        if(idx==s.size()) return c==0;
        bool c1,c2,c3;
        if(dp[idx][c]!=-1) return dp[idx][c];
        if(s[idx]=='(') return helper(s,idx+1,c+1,dp);
        else if(s[idx]==')') return helper(s,idx+1,c-1,dp);
        else{
            c1=helper(s,idx+1,c+1,dp);
            c2=helper(s,idx+1,c,dp);
            c3=helper(s,idx+1,c-1,dp);

        }
        return dp[idx][c]=c1||c2||c3;

    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(s,0,0,dp);
    }
};