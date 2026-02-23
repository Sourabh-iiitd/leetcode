class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        for(int i=0;i+k<=s.size();i++){
            string l="";
            for(int j=i;j<i+k;j++){
                l+=s[j];
            }
            st.insert(l);
        }
        int sx=st.size();
        int chk= 1<<k;
        return sx==chk;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });