class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0;
        char curr = 'a';

        int d1,d2;
        for(auto &x : word){
            d1 = abs(x - curr);
            d2 = 26 - d1;
            ans += (min(d1,d2) + 1);

            curr = x;
        }
        return ans;
    }
};