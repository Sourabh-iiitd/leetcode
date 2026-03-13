class Solution {
public:
    // vector<vector<int>> dp;
    // bool helper(int i, int j, string &s, string &p){
    //     if(i==s.size() && j==p.size()) return true;
    //     if(j==p.size()) return false;
    //     if(i==s.size()){
    //         if(p[j]=='*') return helper(i, j+1, s, p);
    //         return false;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
        
    //     bool check1=false;
    //     bool check2=false;
    //     bool check3=false;
    //     if(i<s.size() && j<p.size() && s[i]==p[j]) check1=helper(i+1,j+1,s,p);
    //     if(j<p.size() && p[j]=='?') check2=helper(i+1,j+1,s,p);
    
    //     if(i<s.size() && j<p.size() && p[j]=='*'){
    //         bool c1= helper(i+1,j,s,p);
    //         bool c2= helper(i,j+1,s,p);
    //         check3=c1||c2;
    //     }
    //     return dp[i][j]=check1 || check2 || check3;

    // }
    // bool isMatch(string s, string p) {
    //     dp.assign(s.size()+1, vector<int>(p.size()+1, -1));
    //     return helper(0,0,s,p);

    // }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));

        dp[n][m] = true;

        for(int j=m-1;j>=0;j--){
            if(p[j]=='*')
                dp[n][j] = dp[n][j+1];
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){

                if(p[j]=='*')
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];

                else if(p[j]=='?' || s[i]==p[j])
                    dp[i][j] = dp[i+1][j+1];
            }
        }

        return dp[0][0];
    }
};