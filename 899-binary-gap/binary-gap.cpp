class Solution {
public:
    int binaryGap(int n) {
        int c = __builtin_popcount(n);
        if(c==1 || c==0) return 0;
        string a="";
        while(n>0){
            int x=n&1;
            a=to_string(x)+a;
            n>>=1;
        }
        
        
        int j=0;
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='1'){
                ans=max(ans,i-j);
                j=i;
                
            }
        }
        return ans;
    }
};