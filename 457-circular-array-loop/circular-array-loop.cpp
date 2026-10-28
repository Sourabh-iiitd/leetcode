class Solution {
public:
    int getNext(vector<int>& nums, bool isForward, int i) {
        bool currentDirection = nums[i] > 0;
        if (isForward != currentDirection) return -1;

        int n = nums.size();
        int nextIndex = ((i + nums[i]) % n + n) % n;
        if (nextIndex == i) return -1;

        return nextIndex;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            
            if (nums[i] == 0) continue;

            bool isForward = nums[i] > 0;
            int slow = i, fast = i;

            while (true) {
                slow = getNext(nums, isForward, slow);
                fast = getNext(nums, isForward, fast);

                if (fast != -1) {
                    fast = getNext(nums, isForward, fast);
                }

              
                if (slow == -1 || fast == -1) break;
                if (slow == fast) return true;
            }
            int current = i;
            while (nums[current] != 0 && (nums[current] > 0) == isForward) {
                int next = ((current + nums[current]) % n + n) % n;
                nums[current] = 0;
                current = next;
            }
        }

        return false;
    }
};