class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        int ans = 0;

        vector<int> right(n);
        vector<bool> seen(26, 0);

        int d = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(!seen[s[i] - 'a']) {
                seen[s[i] - 'a'] = true;
                d++;
            }
            right[i] = d;
        }

        seen.assign(26, 0);
        int left = 0;

        for(int i = 0; i < n - 1; i++) {
            if(!seen[s[i] - 'a']) {
                seen[s[i] - 'a'] = true;
                left++;
            }

            if(left == right[i + 1])
                ans++;
        }

        return ans;
    }
};