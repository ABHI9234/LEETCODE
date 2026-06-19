class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // Day 0 initialization
        int free = 0;                  // Profit if we own nothing
        int holding = -prices[0];      // Profit if we buy on day 0

        for (int i = 1; i < prices.size(); i++) {
            // Calculate today's optimal states based on yesterday's states
            free = max(free, holding + prices[i] - fee);
            holding = max(holding, free - prices[i]);
        }

        return free; // The max profit when we aren't holding any stock
    }
};