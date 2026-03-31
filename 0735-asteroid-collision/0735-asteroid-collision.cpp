class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int curr = nums[i];
            bool destroyed = false;
            while(st.size() > 0 && st.top() > 0 && curr < 0){
                
                if(abs(st.top()) < abs(curr)){
                    st.pop();
                }
                else if(abs(st.top()) == abs(curr)){
                    st.pop();
                    destroyed = true;
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
            }
            if(destroyed==false){
                st.push(curr);
            }
        }
        vector<int> ans;
        while(st.size() > 0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};