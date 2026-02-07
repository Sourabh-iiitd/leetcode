class Solution {
public:
    int maxDistinct(string s) {
        vector<bool> seen(26, false);
        int cnt = 0;

        for(char c : s){
            if(!seen[c - 'a']){
                seen[c - 'a'] = true;
                cnt++;
            }
        }

        return cnt;
    }
};
