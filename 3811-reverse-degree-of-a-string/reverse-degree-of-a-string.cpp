class Solution {
public:
    int asc(char s){
        return 122-s+1;
    }

    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int c=asc(s[i]);
            int pro=(i+1)*c;
            ans+=pro;
        }
        return ans;
    }
};