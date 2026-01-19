class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int ans=0;
        for(int i=0;i<points.size()-1;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            int x2=points[i+1][0];
            int y2=points[i+1][1];
            int diff1=abs(x2-x1);
            int diff2=abs(y2-y1);
            if(diff1==diff2) ans+=diff1;
            else ans+=max(diff1,diff2);
        }
        return ans;
    }
};