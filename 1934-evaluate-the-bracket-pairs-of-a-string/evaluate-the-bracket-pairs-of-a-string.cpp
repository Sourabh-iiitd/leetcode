class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string> mpp;
        for(int i=0;i<knowledge.size();i++){
            mpp[knowledge[i][0]]=knowledge[i][1];
        }
        
        int cnt=0;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='(') {
                string key="";
                i++;

                while(i<s.size() && s[i]!=')'){
                    key+=s[i];
                    i++;
                }
                if (mpp.count(key)) {
                    ans += mpp[key];
                } else {
                    ans += '?';
                }
            }else{
                ans+=s[i];
            }
        }


        return ans;
    }
};