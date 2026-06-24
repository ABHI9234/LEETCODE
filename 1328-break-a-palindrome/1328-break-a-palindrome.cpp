class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()==1) return "";
        int c = 0;
        int n = s.size();

        for(int i =0;i<n/2;i++){
            if(s[i]!='a'){
                s[i] = 'a';
                c++;
                break;
            }
        }
        if(c==0) s[n-1] = 'b';
        return s;
    }
};