class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> premax(n);
        vector<int> sufmax(n);
        premax[0]=heights[0];
        sufmax[n-1] = heights[n-1];
        for(int i =1;i<n;i++){
            premax[i] = max(premax[i-1],heights[i]);
        }
        for(int i =n-2;i>=0;i--){
            sufmax[i] = max(sufmax[i+1],heights[i]);
        }
        int total =0;
        for(int i =0;i<n;i++){
            if(heights[i]<premax[i] && heights[i]<sufmax[i]){
                total += min(premax[i],sufmax[i])-heights[i];
            }
        }
        return total;
    }
};