class Solution {
public:
    bool isSubsequence(string& s, string& t) {
        int i=0;
        int j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[i]){
                i++;
            }
            j++;
        }
        return i==s.size(); 
    }
    bool canMakeSubsequence(string s, string t) {
        if(s.size()>t.size()) return false;
        if(isSubsequence(s,t)) return true;

        int n=s.size();
        int m=t.size();

        vector<int> left(n, -1);
        vector<int> right(n, m);


        int p1 = 0;
        for (int i = 0; i < n; i++) {
            while (p1 < m && t[p1] != s[i]) {
                p1++;
            }
            if (p1 < m) {
                left[i] = p1;
                p1++; 
            } else {
                break; 
            }
        }

    
        int p2 = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (p2 >= 0 && t[p2] != s[i]) {
                p2--;
            }
            if (p2 >= 0) {
                right[i] = p2;
                p2--; 
            } else {
                break;
            }
        }


        for (int i = 0; i < n; i++) {
            int L = (i == 0) ? -1 : left[i - 1];
            int R = (i == n - 1) ? m : right[i + 1];

            if ((i == 0 || L != -1) && (i == n - 1 || R != m)) {
                if (R - L > 1) {
                    return true;
                }
            }
        }

        return false;

    }
};