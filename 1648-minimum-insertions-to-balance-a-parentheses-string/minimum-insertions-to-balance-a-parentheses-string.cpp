class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int opn=0;
        int n= s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='(') opn++;
            else{
                if(i+1<n && s[i+1]==')'){
                    i++;
                    if(opn>0) opn--;
                    else ans++;
                }
                else{
                    ans++;
                    if(opn>0) opn--;
                    else ans++;
                }
            }
        }
        ans+= opn*2;
        return ans;
    }
};