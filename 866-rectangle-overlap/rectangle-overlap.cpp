class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1= rec1[0];
        int y1= rec1[1];
        int x2= rec1[2];
        int y2= rec1[3];
        
        int x11= rec2[0];
        int y11= rec2[1];
        int x22= rec2[2];
        int y22= rec2[3];

        if(max(x1, x11) < min(x2, x22) && max(y1, y11) < min(y2, y22)  ) return true;
        else return false;
    }
};