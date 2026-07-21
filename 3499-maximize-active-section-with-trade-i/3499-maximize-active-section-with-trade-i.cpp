class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int base_ones = 0;
        for (char c : s) {
            if (c == '1') base_ones++;
        }
        string t = "1" + s + "1";
        vector<int> blocks;
        int n = t.length();
        for (int i = 0; i < n; ) {
            char current_char = t[i];
            int count = 0;
            while (i < n && t[i] == current_char) {
                count++;
                i++;
            }
            blocks.push_back(count);
        }
        int k = blocks.size() / 2;
        if (k < 2) {
            return base_ones;
        }
        vector<pair<int, int>> zeros;
        for (int i = 0; i < k; i++) {
            zeros.push_back({blocks[2 * i + 1], i});
        }
        sort(zeros.rbegin(), zeros.rend());
        int max_gain = 0;
        for (int i = 1; i < k; i++) {
            int O_i = blocks[2 * i];           
            int Z_left = blocks[2 * i - 1];    
            int Z_right = blocks[2 * i + 1];   
            int val1 = Z_left + Z_right;
            int val2 = -1e9;
            for (int j = 0; j < min(3, (int)zeros.size()); j++) {
                int z_len = zeros[j].first;
                int z_idx = zeros[j].second;
                if (z_idx != i - 1 && z_idx != i) {
                    val2 = z_len - O_i;
                    break; 
                }
            }
            max_gain = max({max_gain, val1, val2});
        }
        return base_ones + max_gain;
    }
};