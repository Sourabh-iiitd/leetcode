class Solution {
public:
    string count(string s) {
        
        int sm = 0;
        for (char ch : s) {
            sm += ch - '0';
        }
        return to_string(sm);
    }
    string digitSum(string s, int k) {
        while (s.size() > k) {
            int n = s.size();

            vector<string> str;
            int c = 0;
            string yo = "";

            for (int i = 0; i < n; i++) {
                yo += s[i];
                c++;
                if (c == k) {
                    str.push_back(yo);
                    yo = "";
                    c = 0;
                }
            }
            if (!yo.empty()) str.push_back(yo);
            string ans = "";
            for (auto c : str) {
                string nw = count(c);
                ans += nw;
            }
            s = ans;
        }
        return s;
    }
};