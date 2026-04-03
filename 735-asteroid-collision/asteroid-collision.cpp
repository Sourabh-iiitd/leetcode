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
                    }
                    else{
                        as=0;
                        break;
                    }
                    
                }
                if(as!=0) st.push(as);
                    
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};