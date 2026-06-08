class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int s=0;
        for(int i=1;i<200;i++){
            if((abs(n-i)<=k) && (n&i)==0) s+=i;
        }
        return s;
    }
};