class Solution {
public:
    string reverseByType(string s) {
        vector<char> letters;
        vector<char> special;

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                letters.push_back(ch);
            } else
                special.push_back(ch);
        }
        reverse(letters.begin(), letters.end());
        reverse(special.begin(), special.end());

        int i = 0;
        int j = 0;

        for (int x = 0; x < s.size(); x++) {
            if (s[x] >= 'a' && s[x] <= 'z') {
                s[x] = letters[i];
                i++;
            } else {
                s[x] = special[j];
                j++;
            }
        }

        return s;
    }
};