class Solution {
public:
    string finalString(string s) {
        vector<char> arr;

        for (char x : s) {
            if (x != 'i') {
                arr.push_back(x);
            } else {
                reverse(arr.begin(), arr.end());
            }
        }

        return string(arr.begin(), arr.end());
    }
};
