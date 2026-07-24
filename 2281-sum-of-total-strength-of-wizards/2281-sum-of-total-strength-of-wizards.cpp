// class Solution {
// public:
//     int totalStrength(vector<int>& strength) {
//         int n = strength.size();
//         int total = 0;
//         int mod = 1000000007;
//         for(int i =0;i<n;i++){
//             int csum = 0;
//             int mn = strength[i];
//             for(int j = i;j<n;j++){
//                 csum += strength[j]%mod;
//                 mn = min(mn,strength[j]);
//                 total +=(csum*mn)%mod;
//             }
//         }
//         return total%mod;
//     }
// };


class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        long long mod = 1e9 + 7;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && strength[st.back()] >= strength[i]) {
                right[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }        
        st.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && strength[st.back()] > strength[i]) {
                left[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = (pref[i] + strength[i]) % mod;
        }
        vector<long long> ppref(n + 2, 0);
        for (int i = 0; i <= n; ++i) {
            ppref[i + 1] = (ppref[i] + pref[i]) % mod;
        }
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            int L = left[i];
            int R = right[i];
            long long left_count = i - L;
            long long right_count = R - i;
            long long right_sum = (ppref[R + 1] - ppref[i + 1] + mod) % mod;
            long long left_sum = (ppref[i + 1] - ppref[L + 1] + mod) % mod;
            long long total_sum = (left_count * right_sum % mod - right_count * left_sum % mod + mod) % mod;
            total = (total + total_sum * strength[i] % mod) % mod;
        }
        
        return total;
    }
};