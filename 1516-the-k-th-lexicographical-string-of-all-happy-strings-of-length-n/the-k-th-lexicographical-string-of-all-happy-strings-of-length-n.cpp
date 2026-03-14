class Solution {
public:

    void helper(int n,vector<string> &ans,string s){
        if(s.size()==n){
            ans.push_back(s);
            return ;
        }
        char prev;
        if(!s.empty())  prev=s.back();
        if(s.empty() || prev!='a') helper(n,ans,s+"a");
        if(s.empty() || prev!='b') helper(n,ans,s+"b");
        if(s.empty() || prev!='c') helper(n,ans,s+"c");

        // return ans;
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        helper(n,ans,"");
        int sz=ans.size();
        if(k>sz) return "";
        return ans[k-1]; 
    }
};