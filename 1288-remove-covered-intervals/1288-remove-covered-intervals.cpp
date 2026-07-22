class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; 
            }
            return a[0] < b[0];
        });
        stack<pair<int,int>> st;
        for(auto it: intervals){
            if(st.size()>0 && st.top().first<=it[0] && st.top().second>=it[1]) continue;
            else st.push({it[0],it[1]});
        }
        return st.size();
    }
};