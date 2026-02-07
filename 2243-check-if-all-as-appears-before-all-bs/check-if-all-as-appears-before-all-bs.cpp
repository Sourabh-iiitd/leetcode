class Solution {
public:
    int minimumDeletions(string s) {
        
        int n=s.size();
        int a=0;
        int b=0;
        
        for(char c : s) if(c == 'a') a++;
        int mini=a;
        for(int i=0;i<n;i++){
        
            if(s[i]=='b') b++;
            if(s[i]=='a') a--;
            mini=min(mini,a+b);
        }
    

        return mini;
    }
    bool checkString(string s) {
        if(minimumDeletions(s)==0) return true;
        else return false;
    }
};