class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        unordered_set<char> st;
        unordered_map<char,int> first,last;

        for(int i=0;i<n;i++){
            char ch=word[i];

            if(isupper(ch)){
                char low=tolower(ch);
                if(!first.contains(low)) first[low]=i;
            }
            else{
                last[ch]=i;
            }

            st.insert(ch);
        }

        vector<char> ans;

        for(char i='a';i<='z';i++){
            if(st.contains(i)){
                char chk=toupper(i);
                if(st.contains(chk)) ans.push_back(i);
            }
        }

        int c=0;

        for(int i=0;i<ans.size();i++){
            int up=first[ans[i]];
            int low=last[ans[i]];

            if(low<up) c++;
        }

        return c;
    }
};