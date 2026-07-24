class Solution {
public:
    int minOperations(string s) {
        int c1 = 0;
        int c2 = 0;
        int n = s.size();
        string s1,s2;
        for(int i =0;i<n;i++){
            if(i%2==0){
                s1+='0';
                s2+='1';
            }
            else{
                s1+='1';
                s2+='0';
            }
        }
        for(int i =0;i<n;i++){
            if(s1[i]!=s[i]) c1++;
            if(s2[i]!=s[i]) c2++;
        }
        return min(c1,c2);
    }
};