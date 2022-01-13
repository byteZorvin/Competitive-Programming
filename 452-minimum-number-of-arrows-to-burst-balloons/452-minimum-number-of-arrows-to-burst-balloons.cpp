class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int start = points[0][0], end = points[0][1], arrows = 1;
        for(auto point: points) {
            if(point[0] > end) {
                arrows++, start = point[0], end = point[1];
            }
            else
                end = min(end, point[1]);
        }
        return arrows;
    }
};