class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = ranges::max(nums);
        int mn = ranges::min(nums);
        return gcd(mx,mn);
    }
};