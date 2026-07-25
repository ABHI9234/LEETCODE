class Solution {
public:
    int maxProduct(int n) {
        vector<int> dig;
        while(n>0){
            int x = n%10;
            dig.push_back(x);
            n/=10;
        }
        sort(dig.begin(),dig.end());
        int v = dig.size();
        return dig[v-1]*dig[v-2];
    }
};