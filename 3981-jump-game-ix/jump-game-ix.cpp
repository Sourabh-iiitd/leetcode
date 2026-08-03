class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return {};

        vector<int> max_left(n);
        max_left[0]=nums[0];
        for (int i=1; i < n; i++) {
            max_left[i]=max(max_left[i-1], nums[i]);
        }

        vector<int> min_right(n);
        min_right[n-1]=nums[n-1];
        for (int i=n-2; i >= 0; i--) {
            min_right[i]=min(min_right[i+1], nums[i]);
        }

        vector<int> ans(n);
        int chunk_start=0;

        for (int i=0; i < n; i++) {
            if (i==n-1 || max_left[i] <= min_right[i+1]) {

                int max_val=max_left[i];

                for (int j=chunk_start; j <= i; j++) {
                    ans[j]=max_val;
                }

                chunk_start=i+1;
            }
        }

        return ans;
    }
};