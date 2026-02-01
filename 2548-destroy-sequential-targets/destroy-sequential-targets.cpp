class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int> cnt;

        for(int x : nums)
            cnt[x % space]++;

        int ans=INT_MAX;
        int maxCnt=0;

        for(int x : nums) {
            int r=x % space;

            if (cnt[r] > maxCnt) {
                maxCnt=cnt[r];
                ans=x;
            }
            else if (cnt[r] == maxCnt) {
                ans=min(ans, x);
            }
        }

        return ans;
    }
};
