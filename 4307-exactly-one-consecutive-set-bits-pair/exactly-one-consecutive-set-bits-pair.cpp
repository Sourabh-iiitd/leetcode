class Solution {
public:
    bool consecutiveSetBits(int n) {
        int pairCount=0;

        while(n>0){
            if((n&1)==1&&((n>>1)&1)==1){
                pairCount++;
            }
            n>>=1;
        }

        return pairCount==1;
    }
};