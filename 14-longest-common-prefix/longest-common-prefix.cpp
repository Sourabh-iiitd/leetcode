class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string match=strs[0];

        for(int i=1;i<strs.size();i++){
            string s="";
            int j=0;
            while(j<strs[0].size() && j<strs[i].size() && strs[i][j]==match[j]){
                s+=strs[i][j];
                j++;
            }
            match=s;
            if(s=="") return "";
        }

        return match;
    }
};