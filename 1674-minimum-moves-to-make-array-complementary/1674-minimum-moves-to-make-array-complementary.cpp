class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        // Difference array to track moves for every possible sum [2, 2*limit]
        // Size is 2*limit + 2 to handle boundaries and 1-based indexing comfortably
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            // 1. Every pair needs at least 2 moves for any sum in [2, 2*limit]
            // We mark the start (+2) and end (-2)
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // 2. Discount: For certain sums, we only need 1 move.
            // Range for 1 move: [min(a,b) + 1, max(a,b) + limit]
            int oneMoveStart = min(a, b) + 1;
            int oneMoveEnd = max(a, b) + limit;
            
            diff[oneMoveStart] -= 1;     // Change 2 moves to 1
            diff[oneMoveEnd + 1] += 1;   // Revert back to 2 moves after range

            // 3. Discount: For exactly the current sum, we need 0 moves.
            int zeroMoveSum = a + b;
            
            diff[zeroMoveSum] -= 1;      // Change 1 move to 0
            diff[zeroMoveSum + 1] += 1;  // Revert back to 1 move after the point
        }

        // Now calculate the prefix sum to find the minimum moves
        int minMovesRequired = n; // Initialized to max possible moves
        int currentMoves = 0;
        
        for (int i = 2; i <= 2 * limit; i++) {
            currentMoves += diff[i];
            minMovesRequired = min(minMovesRequired, currentMoves);
        }

        return minMovesRequired;
    }
};