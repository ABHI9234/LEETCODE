class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string res = "";
        for(int i =0;i<n;i++){
            if(s[i]!='*' && s[i]!='#' && s[i]!='%') res+=s[i];
            else if(s[i]=='*'){
                if(res.size()>0)res.pop_back();
                else continue;
            }
            else if(s[i]=='#') res+=res;
            else reverse(res.begin(),res.end());
        }
        return res;
    }
};