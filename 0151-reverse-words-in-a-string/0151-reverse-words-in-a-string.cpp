class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string a="";
        stack<string> st;
        for(int i =0;i<n;i++){
            if(s[i]!=' ') a+=s[i];
            else{
                if(a!="")
                {    st.push(a);
                    a="";}
            }
        }
        if (a != "") st.push(a);
        string z="";
        while(st.size()>0){
            z+=st.top();
            st.pop();
            if(!st.empty()) z+= ' ';
            
        }
        return z;
    }
};