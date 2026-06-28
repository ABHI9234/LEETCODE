class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        bool flag = false;
        int mn = INT_MAX;
        int idx = 0;
        int n = arr.size();
        for(int i =0;i<n;i++){
            if(arr[i]==1){
                flag = true;
                break;
            }
        }
        if(flag==false){
            for(int i =0;i<n;i++){
                if(arr[i]<mn){
                    mn = min(mn,arr[i]);
                    idx = i;
                }
            }
            arr[idx] = 1;
        }
        
        sort(arr.begin(),arr.end());
        for(int i =1;i<n;i++){
            if(abs(arr[i]-arr[i-1])<=1) continue;
            else arr[i] = 1+arr[i-1];
        }
        return arr[n-1];
    }
};