class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum =0;
        for(int i =0;i<minutes;i++){
            if(grumpy[i]==1){
                sum=+customers[i];
            }
        }
        int i =1;
        int j = minutes;
        int maxsum = sum;
        int idx = 0;
        int n = customers.size();
        while(j<customers.size()){
            if(grumpy[j]==1) sum+= customers[j];
            if (grumpy[i-1] == 1) sum -= customers[i-1];
            if(maxsum<sum){
                maxsum = sum;
                idx = i;

            }
            i++;
            j++;
        }
        int maxx = 0;
        for(int i =idx;i<idx+minutes;i++){
            grumpy[i]=0;
        }
        for(int i =0;i<n;i++){
            if(grumpy[i]==0){
                maxx+=customers[i];
            }
        }
        return maxx;
        
    }
};