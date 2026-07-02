class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        if (occupiedIntervals.empty()) return {};
        int n=occupiedIntervals.size();


        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> merged;


        int x=occupiedIntervals[0][0];
        int y=occupiedIntervals[0][1];

       
        for (int i=1; i < n; i++) {
        
            if (occupiedIntervals[i][0]<=y+1) {
                y=max(y, occupiedIntervals[i][1]);
            } 
            else {
                
                merged.push_back({x, y});
             
                x=occupiedIntervals[i][0];
                y=occupiedIntervals[i][1];
            }
        }
       
        merged.push_back({x, y});
        vector<vector<int>> result;
        for (const auto& interval : merged) {
            int s=interval[0];
            int e=interval[1];

            if (freeEnd < s || freeStart > e) {
                result.push_back({s, e});
            } 
            else {
                if (s < freeStart) {
                    result.push_back({s, freeStart - 1});
                }
                if (e > freeEnd) {
                    result.push_back({freeEnd+1, e});
                }
            }
        }

        return result;
    }
};