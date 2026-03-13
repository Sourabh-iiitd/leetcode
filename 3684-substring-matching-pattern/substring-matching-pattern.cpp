class Solution {
public:
    bool helper(string &s, string &p, int i, int j){
        if (j == p.size()) return true;

        if (i == s.size()) {
            return (j == p.size() - 1 && p[j] == '*');
        }

        if (p[j] == '*') {
            return helper(s,p,i,j+1) || helper(s,p,i+1,j);
        }

        if (s[i] == p[j]) return helper(s,p,i+1,j+1);

        return false;
    }

    bool hasMatch(string s, string p) {
        for (int i = 0; i <= s.size(); i++) {
            if (helper(s,p,i,0)) return true;
        }
        return false;
    }
};