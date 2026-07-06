class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        
        for (int i = 0; i < intervals.size() - 1; i++) {
            int a = intervals[i][0];
            int b = intervals[i][1];
            int c = intervals[i+1][0];
            int d = intervals[i+1][1];
    
            if (b >= d) { 
                n--;
                intervals[i+1] = intervals[i]; 
            }
            else if (a == c && b <= d) {
                n--;
            }
        }
        return n;
    }
};