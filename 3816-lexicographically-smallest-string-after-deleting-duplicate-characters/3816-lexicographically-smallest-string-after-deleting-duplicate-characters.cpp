class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }
        stack<char> stk;
        for (char c : s) {
            while (!stk.empty() && stk.top() > c && cnt[stk.top()] > 1) {
                cnt[stk.top()]--; 
                stk.pop();        
            }
            stk.push(c);
        }
        while (!stk.empty() && cnt[stk.top()] > 1) {
            cnt[stk.top()]--;
            stk.pop();
        }
        string result = "";
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};