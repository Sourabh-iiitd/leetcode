class Solution {
public:

    // void helper(int n,vector<string> &ans,string s){
    //     if(s.size()==n){
    //         ans.push_back(s);
    //         return ;
    //     }
    //     // char prev;
    //     // if(!s.empty())  prev=s.back();
    //     if(s.empty() || s.back()!='a') helper(n,ans,s+"a");
    //     if(s.empty() || s.back()!='b') helper(n,ans,s+"b");
    //     if(s.empty() || s.back()!='c') helper(n,ans,s+"c");

    //     // return ans;
    // }
    // string getHappyString(int n, int k) {
    //     vector<string> ans;
    //     helper(n,ans,"");
    //     int sz=ans.size();
    //     if(k>sz) return "";
    //     return ans[k-1]; 
    // }

    //iterative
    string getHappyString(int n, int k) {

        vector<vector<string>> dp(n + 1);

        dp[1] = {"a", "b", "c"};

        for(int len = 2; len <= n; len++){
            for(string s : dp[len - 1]){
                char last = s.back();

                if(last != 'a') dp[len].push_back(s + "a");
                if(last != 'b') dp[len].push_back(s + "b");
                if(last != 'c') dp[len].push_back(s + "c");
            }
        }

        if(k > dp[n].size()) return "";
        return dp[n][k - 1];
    }
};