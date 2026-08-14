class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            vector<int> count(26, 0);
            for(int j=i;j<n;j++) {
                int index=s[j]-'a';
                count[index]++;
                if (count[index]>2) {
                    break;
                }
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};