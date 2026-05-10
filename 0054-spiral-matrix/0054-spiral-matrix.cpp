class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        int m = matrix[0].size();
        int minr = 0, minc = 0;
        int maxr = n - 1, maxc = m - 1;
        while (minr <= maxr && minc <= maxc) {
            for (int j = minc; j <= maxc; j++) {
                result.push_back(matrix[minr][j]);
            }
            minr++;
            for (int i = minr; i <= maxr; i++) {
                result.push_back(matrix[i][maxc]);
            }
            maxc--;
            if (minr <= maxr) {
                for (int j = maxc; j >= minc; j--) {
                    result.push_back(matrix[maxr][j]);
                }
                maxr--; 
            }
            if (minc <= maxc) {
                for (int i = maxr; i >= minr; i--) {
                    result.push_back(matrix[i][minc]);
                }
                minc++; 
            }
        }
        return result;
    }
};