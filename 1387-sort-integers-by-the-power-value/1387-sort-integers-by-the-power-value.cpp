class Solution {
public:
    typedef pair<int,int> pi;
    int getKth(int lo, int hi, int k) {
        priority_queue<pi>pq;
        for(int i = lo;i<=hi;i++){
            int step = 0;
            int y = i;
            while(y!=1){
                if(y%2==0) y = y/2;
                else y = (y*3)+1;
                step++;
            }
            pq.push({step,i});
            if(pq.size()>k) pq.pop();
        }
        return pq.top().second;
    }
};