class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int ans=1;
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++){
            
            if(mpp[s[i]]>0) {
                ans++;
                mpp.clear();
            }
            mpp[s[i]]++;
        }
        return ans;
    }
};