class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) return false;
        int min=0;
        int max=0;
        for(int i=0;i<s.size();i++){
            if(locked[i]!='1'){
                if(min-1<0) min=0;
                else min--;
                max++;
            }
            else if(s[i]=='(') {
                min++;
                max++;
            }
            else if(s[i]==')'){
                if(min-1<0) min=0;
                else min--;
                if(max-1<0) return false;
                else max--;
            }
            
        }
        if(max<0) return false;
        return min==0;
    }
};