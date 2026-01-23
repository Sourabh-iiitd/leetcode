class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') {
                min++;
                max++;
            }
            else if(s[i]==')'){
                if(min-1<0) min=0;
                else min--;
                if(max-1<0) return false;
                else max--;
            }
            else{
                if(min-1<0) min=0;
                else min--;
                max++;
            }
        }
        if(max<0) return false;
        return min==0;
    }
};