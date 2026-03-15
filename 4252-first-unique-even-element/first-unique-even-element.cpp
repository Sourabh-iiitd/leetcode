class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int x : nums)
            mpp[x]++;
        
        for (int x : nums)
            if (x % 2 == 0 && mpp[x] == 1)
                return x;
    	
        return -1;
    }
};