class Solution {
public:

    void solve(int n, string s, vector<string> &ans){
        if(s.size() == n){
            ans.push_back(s);
            return;
        }

        solve(n, s + "0", ans);
        solve(n, s + "1", ans);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();

        vector<string> all;
        solve(n, "", all);

        unordered_set<string> st(nums.begin(), nums.end());

        for(auto &s : all){
            if(st.find(s) == st.end()){
                return s;
            }
        }

        return "";
    }
};