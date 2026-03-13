class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        long long ans = 0;
        long long prev = 1e18;

        for(int h : maximumHeight){
            long long curr = min((long long)h, prev - 1);
            if(curr <= 0) return -1;
            ans += curr;
            prev = curr;
        }

        return ans;
    }
};