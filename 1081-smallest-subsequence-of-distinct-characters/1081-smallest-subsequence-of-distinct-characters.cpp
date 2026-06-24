class Solution {
public:
    string smallestSubsequence(string s) {
        string v="";
        stack<char> st;
        int n = s.size();
        vector<int> lo(26);
        vector<bool> instack(26,false);
        for(int i =0;i<n;i++) lo[s[i]-'a'] = i;
        for(int i =0;i<n;i++){
            if(instack[s[i]-'a']) continue;
            while(st.size()>0 && st.top()>s[i] && lo[st.top()-'a']>i){
                instack[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            instack[s[i]-'a']=true;
        }
        while(st.size()>0){
            v+=st.top();
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;

    }
};