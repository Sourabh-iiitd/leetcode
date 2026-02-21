class Solution {
public:
    int setbits(int n){
        int c=0;
        while(n>0){
            c+=(n&1);
            n>>=1;
        }
        return c;
    }
    // bool isprime(int n){
    //     if()
    // }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        set<int> st={2,3,5,7,11,13,17,19};
        for(int i=left;i<=right;i++){
            int sb=setbits(i);
            if(st.count(sb)) ans++;

        }
        return ans;
    }
};