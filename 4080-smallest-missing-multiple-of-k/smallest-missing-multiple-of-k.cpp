class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> chk(nums.begin(), nums.end());
        for(int i=1;i<=101;i++){
            int num= k*i;
            if(!chk.count(num)) return num;
        }
        return 0;
    }
};