class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        vector<int> prefS(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cnt++;
            prefS[i] = cnt;
        }

        vector<bool> ans;

        for (string t : strs) {
            int fixedOnes = 0;
            int q = 0;
            for (char c : t) {
                if (c == '1') fixedOnes++;
                else if (c == '?') q++;
            }

            int need = totalOnes - fixedOnes;
            if (need < 0 || need > q) {
                ans.push_back(false);
                continue;
            }

            
            for (int i = n - 1; i >= 0; i--) {
                if (t[i] == '?') {
                    if (need > 0) {
                        t[i] = '1';
                        need--;
                    } else {
                        t[i] = '0';
                    }
                }
            }


            int prefT = 0;
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (t[i] == '1') {
                    prefT++;
                }
                if (prefT > prefS[i]) {
                    ok = false;
                    break;
                }
            }

            ans.push_back(ok);
        }

        return ans;
    }
};