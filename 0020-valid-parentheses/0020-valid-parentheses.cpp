class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                if(st.empty()) return false; 
                if(c == ')' && st.top() == '(') st.pop();
                else if(c == '}' && st.top() == '{') st.pop();
                else if(c == ']' && st.top() == '[') st.pop();
                else return false; 
            }
        }
        return st.empty();
    }
};