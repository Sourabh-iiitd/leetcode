class Solution {
public:
    string trimTrailingVowels(string s) {
        set<char> st={'a','e','i','o','u'};
        if(!st.contains(s[s.size()-1])) return s;
        int i=s.size()-1;
        while(i>0 && st.contains(s[i])){
            i--;
        }
        if(i==0 && st.contains(s[0])) return "";
        return s.substr(0,i+1);
    }
};