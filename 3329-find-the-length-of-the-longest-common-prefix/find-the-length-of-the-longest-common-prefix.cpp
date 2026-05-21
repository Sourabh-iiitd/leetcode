class Solution {
public:
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> possible_prefix;
        for(int i=0;i<arr1.size();i++){
            int num=arr1[i];
            string s=to_string(num);
            string put="";
            for(int j=0;j<s.size();j++){
                put+=s[j];
                possible_prefix.insert(put);
            }

        }
        int ans=0;
        for(int i=0;i<arr2.size();i++){
            int num=arr2[i];
            string s=to_string(num);
            string put="";
            for(int j=0;j<s.size();j++){
                put+=s[j];
                if(possible_prefix.contains(put)) ans=max(ans,(int)put.size());
            }

        }
        return ans;
    }
};