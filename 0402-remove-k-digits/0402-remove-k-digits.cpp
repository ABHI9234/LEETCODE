class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(int i = 0; i < n; i++){
            while(k > 0 && !st.empty() && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        string s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        int i = 0;
        while (i < s.size() && s[i] == '0') {
            i++;
        }

        string result = s.substr(i);
        return result.empty() ? "0" : result;
    }
};