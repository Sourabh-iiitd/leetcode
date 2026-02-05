class Solution {
public:
    string reversePrefix(string s, int k) {
        string s1=s.substr(0,k);
        string s2=s.substr(k,s.size());
        reverse(s1.begin(),s1.end());
        string ans="";
        ans+=s1;
        ans+=s2;
        return ans;
    }
};