// class Solution {
// public:
//     long long minArraySum(vector<int>& nums) {
//         int max_val = 0;
//         for(int num : nums) {
//             if(num > max_val) max_val = num;
//         }
        
//         vector<int> count(max_val + 1, 0);
//         for(int num : nums) {
//             count[num]++;
//         }
        
//         for(int i = 1; i <= max_val; i++) {
//             if(count[i] == 0) continue; 
            
//             for(int j = i * 2; j <= max_val; j += i) {
//                 if(count[j] > 0) {
//                     count[i] += count[j];
//                     count[j] = 0; 
//                 }
//             }
//         }
        
//         long long sum = 0;
//         for(long long i = 1; i <= max_val; i++) {
//             if(count[i] > 0) {
//                 sum += (i * count[i]);
//             }
//         }
        
//         return sum;
//     }
// };
// 2-Factor method
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int max_val = 0;
        for (int num : nums) {
            if (num > max_val) max_val = num;
        }

        // Fast O(1) lookup array to check if a factor exists in the original array
        vector<bool> present(max_val + 1, false);
        for (int num : nums) {
            present[num] = true;
        }

        long long sum = 0;

        for (int num : nums) {
            int best = num;               // Default: no smaller factor found
            int best_large_factor = num;  // Fallback for num / i

            // Only loop up to the square root of the number
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    // Check the smaller factor (i) first
                    // Since i starts at 1 and grows, the first one we find is guaranteed to be the absolute minimum
                    if (present[i]) {
                        best = i;
                        break; 
                    }
                    
                    // Check the larger complementary factor (num / i)
                    // As i grows, (num / i) shrinks. We want the smallest one.
                    if (present[num / i]) {
                        if (num / i < best_large_factor) {
                            best_large_factor = num / i;
                        }
                    }
                }
            }

            // If we didn't find a small factor 'i', fall back to the smallest 'num / i' we found
            if (best == num) {
                best = best_large_factor;
            }

            sum += best;
        }

        return sum;
    }
};