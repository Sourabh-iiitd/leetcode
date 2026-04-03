class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        for(int as: asteroids){
            if(as>0){
                st.push(as);
            }
            else{
                while(!st.empty() && st.top()>0){
                    if(abs(as) == st.top()){
                        st.pop();
                        as=0;
                        break;
                    }
                    else if(abs(as)>st.top()){
                        st.pop();
                        // st.push(as);
                    }
                    else{
                        as=0;
                        break;
                    }
                    
                }
                if(as!=0) st.push(as);
                    
            }
        }
    
        vector<int> ans(st.size());
        for(int i = st.size()-1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};