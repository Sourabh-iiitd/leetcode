class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]); 
        }
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            char c=st.top();
            ans+=c;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        int nonZeroIdx = 0;
        while(nonZeroIdx < ans.size() && ans[nonZeroIdx] == '0') {
            nonZeroIdx++;
        }
        ans = ans.substr(nonZeroIdx);
       
        return ans.empty() ? "0" : ans;
    }
};