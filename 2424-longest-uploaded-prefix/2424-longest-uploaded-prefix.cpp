class LUPrefix {
public:
    vector<int> v;
    int prefix;
    LUPrefix(int n) {
        v.resize(n+1,0);
        prefix = 0;
    }
    
    void upload(int video) {
        v[video]=1;
    }
    
    int longest() {
        while (prefix + 1 < v.size() && v[prefix + 1] == 1) {
            prefix++; 
        }
        return prefix;
    }
};