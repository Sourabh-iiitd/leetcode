class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        
        for(char c : s){
            if( c=='('){
                st.push('(');
            }

            else if( c==')'){
                if(st.empty()) return false;
                if(st.top()=='(') st.pop();
                else st.push(')');
            }

            else if( c=='{') st.push('{');

            else if( c=='}'){
                if(st.empty()) return false;
                if(st.top()=='{') st.pop();
                else st.push('}');
            }

            else if( c=='[') st.push('[');

            else if( c==']'){
                if(st.empty()) return false;
                if(st.top()=='[') st.pop();
                else st.push(']');
            }

            
        }


        return st.empty();
    }
};