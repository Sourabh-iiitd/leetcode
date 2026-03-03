class Solution {
public:
    string dp[21];
    string rev(string x) {
        int yo = x.size() - 1;
        int go = 0;

        while (go < yo) {
            swap(x[yo], x[go]);
            go++;
            yo--;
        }

        return x;
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
        if(dp[i]!="") return dp[i];
        string prev = helper(i-1);
        return dp[i]=prev + "1" + rev(invert(prev));
    }

    char findKthBit(int n, int k) {
        // memset(dp,"",sizeof(dp)); //string obj kelie kam ni krta ..int char etc krta
        for(int i = 0; i < 21; i++) dp[i] = "";
        string ans = helper(n);
        return ans[k-1];  
    }
};