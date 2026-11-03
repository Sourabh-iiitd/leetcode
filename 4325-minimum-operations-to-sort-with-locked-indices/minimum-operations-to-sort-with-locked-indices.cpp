class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int inversions = 0;
        int needed_unlocks = 0;
        int max_so_far = 0;

        for (int i = 0; i < n; i++) {
            max_so_far = max(max_so_far, nums[i]);

         
            if (locked[i] == 1 && (nums[i] != i + 1 || max_so_far != i + 1)) {
                needed_unlocks++;
            }

          
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    inversions++;
                }
            }
        }

        if (needed_unlocks > k) {
            return -1;
        }

        return needed_unlocks + inversions;
    }
};