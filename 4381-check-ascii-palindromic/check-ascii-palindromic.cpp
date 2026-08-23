class Solution {
public:
    string get8BitBinary(char c) {
    string res="";
    for (int i=7;i>=0;i--) {
        res+=((c>>i)&1)? '1':'0';
    }
    return res;
}
    bool isPalindromic(string s) {
        int n=s.size();

        
        string ans="";
        for(char c:s){
            ans+=get8BitBinary(c);
        }

        string rev=ans;
        reverse(rev.begin(), rev.end());

        return ans==rev;



    }
};