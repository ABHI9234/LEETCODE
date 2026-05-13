class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nextGreater; 
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int current = nums2[i];
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }
            if (st.empty()) nextGreater[current] = -1;
            else nextGreater[current] = st.top();
            st.push(current);
        }
        vector<int> result;
        for (int x : nums1) {
            result.push_back(nextGreater[x]);
        }
        return result;
    }
};