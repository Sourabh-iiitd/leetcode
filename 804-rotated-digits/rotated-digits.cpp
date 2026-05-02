class Solution {
public:
    bool check(int num) {
        bool hasChangingDigit = false;
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '3' || ch == '7' || ch == '4')
                return false;
            if (ch == '2' || ch == '5' || ch == '6' || ch == '9') {
                hasChangingDigit = true;
            }
        }
        return hasChangingDigit;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (check(i))
                ans++;
        }
        return ans;
    }
};