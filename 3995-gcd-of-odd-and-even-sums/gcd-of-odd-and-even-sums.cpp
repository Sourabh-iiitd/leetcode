class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sum=n*(2*n+1);
        int even=n*(n+1);
        return gcd(even,sum-even);
    }
};