class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long totalArea=0;
        int minX=INT_MAX, minY=INT_MAX;
        int maxX=INT_MIN, maxY=INT_MIN;
        
        set<pair<int, int>> corners;

        for (const auto& rect : rectangles) {
            int x1=rect[0], y1=rect[1];
            int x2=rect[2], y2=rect[3];

           
            minX=min(minX, x1);
            minY=min(minY, y1);
            maxX=max(maxX, x2);
            maxY=max(maxY, y2);

          
            totalArea += (long long)(x2 - x1) * (y2 - y1);

            
            pair<int, int> pts[4]={{x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}};
            for (const auto& p : pts) {
                if (corners.count(p)) {
                    corners.erase(p);
                } else {
                    corners.insert(p);
                }
            }
        }

       
        long long expectedArea=(long long)(maxX - minX) * (maxY - minY);
        if (totalArea != expectedArea) return false;

        
        if (corners.size() != 4) return false;
        if (!corners.count({minX, minY}) || 
            !corners.count({minX, maxY}) || 
            !corners.count({maxX, minY}) || 
            !corners.count({maxX, maxY})) {
            return false;
        }

        return true;
    }
};