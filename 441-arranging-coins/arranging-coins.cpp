class Solution {
public:
    int arrangeCoins(int n) {
        int tot=n;
        
        for(int i=1;i<=n;i++){
            tot-=i;
            if(tot==0) return i;
            if(tot<0) return i-1;
        }
        return 0;    
    }
};