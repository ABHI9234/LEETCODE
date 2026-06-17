class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        for(int i =0;i<n;i++){
            unordered_map<int,int> mp;
            unordered_map<int,int> mp1;
            for(int j=i;j<n;j++){
                int x=nums[j];
                
                if(mp.count(x)){
                    int of = mp[x];
                    mp1[of]--;
                    if(mp1[of]==0){
                        mp1.erase(of);
                    }
                }
                mp[x]++;
                mp1[mp[x]]++;
                if(mp.size()==1){
                    maxlen = max(maxlen,j-i+1);
                }
                if(mp1.size()==2){
                    auto it = mp1.begin();
                    int f1 = it->first;
                    it++;
                    int f2 = it->first;
                    int mn = min(f1,f2);
                    int mx = max(f1,f2);
                    if(mn*2==mx) maxlen = max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }
};