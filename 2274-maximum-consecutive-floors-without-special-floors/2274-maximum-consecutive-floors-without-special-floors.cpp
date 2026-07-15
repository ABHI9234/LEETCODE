class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int sum = 0;
        int n = special.size();
        if(bottom<special[0]) sum=special[0]-bottom;
        for(int i =1;i<n;i++){
            sum=max(abs(special[i]-special[i-1]-1),sum);
        }
        sum=max(sum,top-special[n-1]);
        return sum;
    }
};