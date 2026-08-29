class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for (int x : nums) {
            string s = "";
            
           
            int z_count = x / (1 << 25);
            s.append(z_count, 'z');
           
            int rem = x % (1 << 25);
            for (int bit = 24; bit >= 0; --bit) {
                if ((rem >> bit) & 1) {
                    s += (char)('a' + bit);
                }
            }
            
            ans.push_back(s);
        }
        return ans;
    }
};