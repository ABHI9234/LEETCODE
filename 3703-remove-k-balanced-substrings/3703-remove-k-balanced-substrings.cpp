class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char, int>> st;        
        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                st.back().second++;
            } else {
                st.push_back({c, 1});
            }
            if (st.back().first == ')' && st.back().second == k) {
                if (st.size() >= 2 && st[st.size() - 2].first == '(' && st[st.size() - 2].second >= k) {
                    st.pop_back();            
                    st.back().second -= k;    
                    if (st.back().second == 0) {
                        st.pop_back();        
                    }
                }
            }
        }
        string ans = "";
        for (auto& p : st) {
            ans += string(p.second, p.first);
        }
        
        return ans;
    }
};