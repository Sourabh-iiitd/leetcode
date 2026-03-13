class Solution {
public:
    vector<vector<int>> dp;
    bool helper(int i, int j, string &s, string &p){
        if(i==s.size() && j==p.size()) return true;
        if(j==p.size()) return false;
        if(i==s.size()){
            if(p[j]=='*') return helper(i, j+1, s, p);
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        bool check1=false;
        bool check2=false;
        bool check3=false;
        if(i<s.size() && j<p.size() && s[i]==p[j]) check1=helper(i+1,j+1,s,p);
        if(j<p.size() && p[j]=='?') check2=helper(i+1,j+1,s,p);
    
        if(i<s.size() && j<p.size() && p[j]=='*'){
            bool c1= helper(i+1,j,s,p);
            bool c2= helper(i,j+1,s,p);
            check3=c1||c2;
        }
        return dp[i][j]=check1 || check2 || check3;

    }
    bool isMatch(string s, string p) {
        dp.assign(s.size()+1, vector<int>(p.size()+1, -1));
        return helper(0,0,s,p);
    }
};