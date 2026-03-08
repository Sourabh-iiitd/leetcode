class Solution {
public:
 //recursion
    // void solve(int n,string s, vector<string> &ans){
    //     if(s.size()==n){
    //         ans.push_back(s);
    //         return;
    //     }
    //     solve(n,s+"1",ans);
    //     solve(n,s+"0",ans);
    // }
    // string findDifferentBinaryString(vector<string>& nums) {
    //     int n=nums[0].size();

    //     vector<string> comp;
    //     solve(n,"",comp);

    //  //ill compare nums to comp .return string if one string not in nums
    //     unordered_set<string>st(nums.begin(), nums.end());

    //     for(auto &s:comp){
    //         if(st.find(s)==st.end()){
    //             return s;
    //         }
    //     }

    //     return "";
       
    // }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans="";

        for(int i=0;i<n;i++){
            if(nums[i][i]=='0') ans+='1';
            else ans+='0';
        }

        return ans;
    }
};