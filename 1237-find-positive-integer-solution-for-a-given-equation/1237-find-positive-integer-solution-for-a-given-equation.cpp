class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> result;
        int x = 1;
        int y = 1000; 
        while (x <= 1000 && y >= 1) {
            int current_val = customfunction.f(x, y);
            if (current_val == z) {
                result.push_back({x, y});
                x++;
                y--;
            } 
            else if (current_val > z) {
                y--;
            } 
            else {
                x++;
            }
        }
        return result;
    }
};