class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        for(int i =0;i<n;i++){
            unordered_map<int,int> mp;
            unordered_map<int,int> mp1;
            for(int j = i;j<n;j++){
                if(mp.count(nums[j])){
                    int x = mp[nums[j]];
                    mp1[x]--;
                    if(mp1[x]==0) mp1.erase(x);
                }
                mp[nums[j]]++;
                mp1[mp[nums[j]]]++;
                if(mp.size()==1) maxlen = max(maxlen,j-i+1);
                if(mp1.size()==2){
                    auto it = mp1.begin();
                    int x = it->first;
                    it++;
                    int y = it->first;
                    int mn = min(x,y);
                    int mx = max(x,y);
                    if(2*mn==mx) maxlen = max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }
};