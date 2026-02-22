class Solution {
public:
    int fact(int n){
        if(n==0) return 1;
        return n*fact(n-1);
    }
    bool isDigitorialPermutation(int n) {
        int chk=0;
        int chk2=n;
        while(n>0){
            int x=n%10;
            int ft=fact(x);
            chk+=ft;
            n/=10;
        }
        string s1 = to_string(chk2);
        string s2 = to_string(chk);

        if(s1.length()!=s2.length()) return false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1==s2;
    }
};