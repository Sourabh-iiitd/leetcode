class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l=0;
        int r=0;
        int m=s.size();
        int n=g.size();
        int ans=0;
        while(l<m && r<n){
            if(s[l]>=g[r]) {
                ans++;
                r++;
                
            }
            l++;
        }
        return ans;
    }
};