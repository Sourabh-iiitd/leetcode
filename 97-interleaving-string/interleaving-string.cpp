class Solution {
public:
    int dp[101][101][201];

    bool helper(int i, int j, int k, string &s1, string &s2, string &s3){
        
        if(i == s1.size() && j == s2.size() && k == s3.size())
            return true;

        if(k >= s3.size())
            return false;

        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        bool res = false;

        if(i < s1.size() && s1[i] == s3[k]) {
            res |= helper(i+1, j, k+1, s1, s2, s3);
        }

        if(j < s2.size() && s2[j] == s3[k]) {
            res |= helper(i, j+1, k+1, s1, s2, s3);
        }

        return dp[i][j][k] = res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();

        if(n + m != k) return false;

        memset(dp, -1, sizeof(dp));

        return helper(0,0,0,s1,s2,s3);
    }
};