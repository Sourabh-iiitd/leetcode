class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd_sum=0;
        int even_sum=0;

        int odd=0;
        int even=0;

        for(int i=1;i<=2*n;i++){
            if (i%2==0 && even!=n) {
                even_sum+=i;
                even++;
            }
            else if(i%2!=0 && odd!=n) {
                odd_sum+=i;
                odd++;
            }
            if(odd==n && even==n) break;
        }
        return gcd(odd_sum, even_sum);
    }
};