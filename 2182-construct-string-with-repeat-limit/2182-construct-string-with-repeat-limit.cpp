class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mp;
        for(char c : s) {
            mp[c]++;
        }
        priority_queue<pair<char, int>> pq;
        for(auto it : mp) {
            pq.push({it.first, it.second});
        }
        string result = "";
        while(!pq.empty()) {
            auto top1 = pq.top();
            pq.pop();
            char ch1 = top1.first;
            int count1 = top1.second;
            int use = min(count1, repeatLimit);
            result.append(use, ch1); 
            count1 -= use;
            if(count1 > 0) {
                if(pq.empty()) {
                    break;
                }
                auto top2 = pq.top();
                pq.pop();
                char ch2 = top2.first;
                int count2 = top2.second;
                result.push_back(ch2);
                count2--;
                if(count2 > 0) {
                    pq.push({ch2, count2});
                }
                pq.push({ch1, count1});
            }
        }
        return result;
    }
};