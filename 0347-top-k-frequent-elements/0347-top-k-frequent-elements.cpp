class Solution {
public:
    typedef pair<int,int> pi;// this is used to give shortcuts
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int x: nums){
            m[x]++;
        }
        //priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        // to declare pair in queue we use the above method or we can do typedef
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto x: m){
            int ele = x.first;
            int freq = x.second;
            // pair<int,int> p = {freq,ele};
            // pq.push(p); like this or
            pq.push({freq,ele});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
         
    }
};