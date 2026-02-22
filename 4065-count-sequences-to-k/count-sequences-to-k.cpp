class Solution {
public:
    int n;
    unordered_map<string, int> mp;
    int fxn(vector<int>& a, long long k, int i, long long top,
            long long bottom) {
        if (i == n) {
            if (top / bottom == k && top % bottom == 0)
                return 1;
            return 0;
        }
        long long gcd = __gcd(top, bottom);

        // geneating my unique string so i can use it in the memo.
        string s = to_string(top / gcd) + "X" + to_string(bottom / gcd) + "X" +
                   to_string(i * 100 + 7) + "XX";

        if (mp.find(s) != mp.end())
            return mp[s];

        int ans = 0;
        // case 1
        ans += fxn(a, k, i + 1, top * a[i], bottom);
        // case 2
        ans += fxn(a, k, i + 1, top, bottom * a[i]);
        // case 3
        ans += fxn(a, k, i + 1, top, bottom);
        return mp[s] = ans;
    }
    int countSequences(vector<int>& a, long long k) {
        mp.clear();

        n = a.size();
        return fxn(a, k, 0, 1, 1);
    }
};