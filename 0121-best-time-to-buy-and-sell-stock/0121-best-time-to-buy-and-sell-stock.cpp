class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnele = INT_MAX;
        int maxdiff = INT_MIN;
        for(int i =0;i<prices.size();i++){
            mnele = min(mnele,prices[i]);
            if(maxdiff<prices[i]-mnele){
                maxdiff = prices[i]-mnele;
            }
        }
        return maxdiff;
    }
};