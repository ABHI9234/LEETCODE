class Solution {
public:
    long long p9(int k){
        long long res=1;
        for(int i = 0;i<k;i++) res*=9;
        return res;
    }
    long long countDistinct(long long n) {
        string s = to_string(n);
        int x= s.size();
        long long ans = 0;
        long long po9 = 9;
        for(int i =1;i<x;i++){
            ans+=po9;
            po9 = po9*9; 
        }
        for(int i = 0;i<x;i++){
            int g = s[i]-'0';
            int valid = max(0,g-1);
            ans+=valid*p9(x-i-1);

            if(g==0) return ans;
            
        }
        return ans+1;
    }
};