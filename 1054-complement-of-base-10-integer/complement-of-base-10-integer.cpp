class Solution {
public:
    string bs(int n){
        
        string s="";
        while(n>0){
            int x=n&1;
            s=to_string(x)+s;
            n>>=1;
        }
        return s;
    }
    int is(string s){
        int n=s.size();
        int x=0;
        for(int i=n-1;i>=0;i--){
            int num=(s[i]-'0')*(1<<(n-i-1));
            x=x+num;
        }
        return x;
    }
    int bitwiseComplement(int n) {
        if(n==0) return 1;

        string s;
        s=bs(n);
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') s[i]='0';
            else if(s[i]=='0') s[i]='1';
        }
        return is(s);

    }
};