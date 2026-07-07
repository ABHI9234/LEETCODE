class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string v;
        int sum = 0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='0') continue;
            else {
                v+=s[i];
                sum+=(s[i]-'0');
            }
        }
        long long x = 0;
        if (!v.empty()) {
            x = stoll(v); 
        }
        return x*sum;
    }
};