class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> ans(n);
        ans[n-1] = -1;
        st.push(nums2[n-1]);
        for(int i =n-2;i>=0;i--){
            while(st.size()>0 && st.top()<= nums2[i]) st.pop();
            if(st.size()==0) ans[i] = -1;
            else ans[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans1(nums1.size());
        for(int i =0;i<nums1.size();i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]) ans1[i] = ans[j];
            }
        }
        return ans1;
    }
};
