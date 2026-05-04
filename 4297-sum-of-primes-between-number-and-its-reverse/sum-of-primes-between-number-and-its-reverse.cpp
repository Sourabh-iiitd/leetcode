class Solution {
public:

    bool prime(int x) {
        if (x <= 1) return false;
        if (x == 2) return true;
        if (x%2==0) return false;

        for (int i=3; i * i <= x; i += 2) {
            if (x%i==0) return false;
        }
        return true;
    }
    int reverse(int n) {
        int r=0;
        while (n > 0) {
            r=r * 10 + (n%10);
            n /= 10;
        }
        return r;
    }

    int sumOfPrimesInRange(int n) {
        int rev=reverse(n);

        int l=min(n, rev);
        int r=max(n, rev);

        int sum=0;

        for (int i=l; i <= r; i++) {
            if (prime(i)) {
                sum += i;
            }
        }

        return sum;
    }
};