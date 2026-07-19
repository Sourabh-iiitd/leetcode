class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26,INT_MIN);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=max(last[s[i]-'a'],i);
        }

        unordered_set<char> st;
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            char curr=s[i];
            if(st.contains(curr)) continue;
            
            while(!st.empty() && stk.top()>curr && last[stk.top() - 'a'] > i){
                    st.erase(stk.top());
                    stk.pop();     
            }
            stk.push(curr);
            st.insert(curr);

        }

        string ans="";
        while(!stk.empty()){
            char c=stk.top();
            ans+=c;
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};