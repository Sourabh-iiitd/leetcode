class Solution {
public:

    unordered_set<string> ans;
    void dfs(string &s, int idx, int bal, int leftb, int rightb, string& current){
        if(leftb<0 || rightb<0 || bal<0) return ;

        if(idx==s.size()){
            if(leftb==0 && rightb==0 && bal==0){
                ans.insert(current);
            }
            return;
        }

        char c= s[idx];

        if(c=='('){
            //nottake
            dfs(s,idx+1, bal, leftb-1, rightb, current);

            //take
            current.push_back('(');
            dfs(s,idx+1, bal+1, leftb, rightb, current);
            current.pop_back();
        }
        else if(c==')'){
            //nottake
            dfs(s,idx+1, bal, leftb, rightb-1, current);

            //take
            current.push_back(')');
            dfs(s,idx+1, bal-1, leftb, rightb, current);
            current.pop_back();
        }
        else{
            current.push_back(c);
            dfs(s, idx+1, bal, leftb, rightb, current);
            current.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        stack<char> st;
        
        for(char c:s){
            if(c=='(') st.push(c);
            else if(c==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
        }

        int min_removals= st.size();

        int leftb=0;
        int rightb=0;
        while(!st.empty()){
            if(st.top()=='(') leftb++;
            else if(st.top()==')') rightb++;
            st.pop();
        }

        string current="";
        dfs(s,0,0,leftb,rightb,current);

        return vector<string> (ans.begin(),ans.end());


    }
};