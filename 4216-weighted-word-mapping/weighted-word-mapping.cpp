class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<int> use;
        for(int i=0;i<words.size();i++){
            int ans1=0;
            for(int j=0;j<words[i].size();j++){
                int val=words[i][j]-'a';
                ans1=(ans1+weights[val])%26;
                
            }
            use.push_back(ans1);
        }
        string ans="";
        for(int num : use){                             
            ans.push_back('z' - num);
        }

        return ans;

    }
};