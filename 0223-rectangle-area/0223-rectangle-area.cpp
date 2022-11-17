class Solution {
    int getArea(int x1, int y1, int x2, int y2) {
        return abs(x2-x1)*abs(y2-y1);
    }
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        bool xCond = bx1 < ax2 && bx2 > ax1;
        bool yCond = by1 < ay2 && by2 > ay1;
        
        int totalArea = getArea(ax1, ay1, ax2, ay2) + getArea(bx1, by1, bx2, by2);
        if(xCond && yCond) {
            int x1 = max(ax1, bx1), x2 = min(ax2, bx2);
            int y1 = max(ay1, by1), y2 = min(ay2, by2);
            int commonArea = getArea(x1, y1, x2, y2);
            totalArea -= commonArea;
        }
        return totalArea;
    }
};