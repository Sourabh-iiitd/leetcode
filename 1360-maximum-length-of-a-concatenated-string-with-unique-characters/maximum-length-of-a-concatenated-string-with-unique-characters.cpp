class Solution {
public:
    vector<string> arr;
    bool isValid(const string& current, const string& next) {
        unordered_set<char> st(current.begin(), current.end());
        for (char ch:next){
            if (st.count(ch)) return false; 
            st.insert(ch);
        }
        return true;
    }

    int solve(int idx, string s) {
        if (idx==arr.size()) {
            return s.length();
        }

      
        int notTake=solve(idx + 1, s);

       
        int take=0;
        if (isValid(s, arr[idx])) {
            take=solve(idx+1,s+arr[idx]);
        }

        return max(take, notTake);
    }

    int maxLength(vector<string>& arr) {
        this->arr=arr;
        return solve(0,"");
    }
};