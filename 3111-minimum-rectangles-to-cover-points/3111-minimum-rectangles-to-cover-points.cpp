class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int c = 0;
        int end = -1;
        for (auto point : points) {
            int x = point[0];
            if (end == -1 || x > end) {
                c++;
                end = x + w; 
            }
        }
        return c;
    }
};