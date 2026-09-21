class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        long long ans=0;
        int n=intervals.size();

        for (int i=0;i<n;i++) {
            auto it=upper_bound(intervals.begin()+i+1, intervals.end(),
                                  vector<int>{intervals[i][1], INT_MAX});
            ans+=(it-(intervals.begin()+i+1));
        }

        return ans;
    }
};