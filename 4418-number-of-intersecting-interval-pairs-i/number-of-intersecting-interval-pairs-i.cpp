class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int ans=0;
        
        for(int i=0;i<intervals.size();i++){   //s1 e1  s2 e2  max(s1,s2) <min(e1,e2)
            for(int j=i+1;j<intervals.size();j++){
                if(max(intervals[i][0], intervals[j][0]) <= min(intervals[i][1], intervals[j][1])) ans++;
            }
        }

        return ans;
    }
};