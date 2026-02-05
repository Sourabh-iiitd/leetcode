class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastIndex[256]; 
        for (int i=0;i<256;i++) lastIndex[i]=-1;

        int maxLen=0;
        int start=0;

        for (int i=0;i<s.length();i++) {
            if (lastIndex[s[i]]>=start){
                start=lastIndex[s[i]]+1; 
            }
            lastIndex[s[i]]=i; 
            maxLen=max(maxLen,i-start+1);
        }

        return maxLen;
    }
};
