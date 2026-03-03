class Solution {
public:
    string rev(string s){
        reverse(s.begin(), s.end());
        return s;
    }

    string invert(string s){
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') ans += '1';
            else ans += '0';
        }
        return ans;
    }

    string helper(int i){
        if(i == 1) return "0";

        string prev = helper(i-1);
        return prev + "1" + rev(invert(prev));
    }

    char findKthBit(int n, int k) {
        string ans = helper(n);
        return ans[k-1];  
    }
};