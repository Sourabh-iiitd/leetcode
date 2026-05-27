class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        unordered_set<char> st;
        for(char c:word){
            st.insert(c);
        }
        int ans=0;
        for(char i='a'; i<='z';i++){
            if(st.contains(i)){
                char chk=toupper(i);
                if(st.contains(chk)) ans++;
            }
        }
        return ans;
    }
};