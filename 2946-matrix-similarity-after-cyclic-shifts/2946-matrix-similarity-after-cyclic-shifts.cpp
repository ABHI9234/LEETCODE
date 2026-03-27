class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k = k%m;
            for(int j=0;j<n;j++){
                vector<int> temp = mat[j];
                reverse(temp.begin()+k,temp.end());
                reverse(temp.begin(),temp.begin()+k);
                reverse(temp.begin(),temp.end());
                if(mat[j]!=temp) return false;
            }   
        return true;
    }
};