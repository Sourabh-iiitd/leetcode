class Solution {
public:
    string helper(string &s, int idx){
        string ans="";
        for(int i=0;i<s.size();i++){
            if(i!=idx){
                ans+=s[i];
            }
        }
        s=ans;
        return s;
    }

    string mergeCharacters(string s, int k) {

        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j] && j-i<=k){
                    helper(s,j);
                    i = -1;   
                    break;
                }
            }
        }
        return s;
    }
};