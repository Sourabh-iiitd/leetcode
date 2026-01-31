class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char> letters;
      

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                letters.push_back(ch);
            }
            else if (ch >= 'A' && ch <= 'Z') {
                letters.push_back(ch);
            }
        }
        reverse(letters.begin(), letters.end());
       

        int i = 0;
    
        for (int x = 0; x < s.size(); x++) {
            if (s[x] >= 'a' && s[x] <= 'z' || s[x] >= 'A' && s[x] <= 'Z') {
                s[x] = letters[i];
                i++;
            }
        }

        return s;
    }
};