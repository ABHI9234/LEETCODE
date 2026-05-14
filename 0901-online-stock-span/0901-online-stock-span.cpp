class StockSpanner {
public:
    // Stack stores pairs of {price, span}
    stack<pair<int, int>> st;

    StockSpanner() {
        // No initialization needed for the stack
    }
    
    int next(int price) {
        int currentSpan = 1; // Every day counts as at least 1 (itself)
        
        // While current price is greater or equal to previous prices
        while (!st.empty() && st.top().first <= price) {
            // Add the span of the previous price to the current one
            currentSpan += st.top().second;
            st.pop();
        }
        
        // Push the result so future calls can use it
        st.push({price, currentSpan});
        
        return currentSpan;
    }
};