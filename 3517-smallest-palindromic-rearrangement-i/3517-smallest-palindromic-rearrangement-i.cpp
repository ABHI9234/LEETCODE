class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> ch(26, 0);
        for(int i = 0; i < s.size(); i++){
            ch[s[i] - 'a']++;
        }
        string v = ""; 
        string y = ""; 
        for(int i = 0; i < 26; i++){
            if(ch[i] > 0){
                v.append(ch[i] / 2, 'a' + i);  
                if(ch[i] % 2 != 0){
                    y += ('a' + i);
                }
            }
        }
        string x = v;
        reverse(x.begin(), x.end());        
        return v + y + x;
        
    }
};