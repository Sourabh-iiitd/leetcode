class Solution {
public:
    bool isRectangleOverlap(int ax1, int ay1, int ax2, int ay2, int bx1,
                            int by1, int bx2, int by2) {
        if (max(ax1, bx1) < min(ax2, bx2) && max(ay1, by1) < min(ay2, by2))
            return true;
        else
            return false;
    }

    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {

        int total1 = abs(ax2 - ax1) * abs(ay2 - ay1);
        int total2 = abs(bx2 - bx1) * abs(by2 - by1);

        if (!isRectangleOverlap(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2))
            return total1 + total2;

        int commonw= min(ax2, bx2) - max(ax1, bx1);
        int commonh= min(ay2, by2) - max(ay1, by1);

        int common = commonw * commonh;

        return total1 + total2 - common;
    }
};