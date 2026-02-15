class Solution {
public:
    int check(string &s,int l,int r){
        while(l >= 0 && r < s.length()){
            if(s[l] != s[r]) break;
            l--;
            r++;
        }
        return r-l-1;
    }
    int expandFromCenter(string &s,int l,int r){
        int n = s.size();
        int t = l;
        int m = r;
        bool skipped = false;
        int len = 0;
        while(l >= 0 && r < n){
            if(s[l] == s[r]){
                len = r-l+1;
                l--;
                r++;
            }
            else{
                if(skipped)return len;
                int ans = 0;
                if(l-1 >= 0 && s[l-1] == s[r]){
                    ans = check(s,l-1,r);
                }
                if(r+1 < n && s[r+1] == s[l]){
                    ans = max(ans,check(s,l,r+1));
                }
                if((l-1 >= 0 || r+1 < n) && ans != 0) return ans;
                else return len+1;
            }
        }
        if(skipped) return len;
        else if(!skipped && (l >= 0 || r <= n-1)) return len+1;
        return t-m+1;
    }
    int almostPalindromic(string s) {
        int len = 0;
        for(int center = 0;center<s.length();center++){
            int lenOdd = expandFromCenter(s,center,center);
            int lenEven = expandFromCenter(s,center,center+1);
            int maxLen = max(lenOdd,lenEven);

            if(maxLen > len){
                len = maxLen;
            }
        }
        return len;
    }
};