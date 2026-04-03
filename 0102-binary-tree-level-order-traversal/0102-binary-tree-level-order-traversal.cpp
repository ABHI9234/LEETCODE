class Solution {
public:
    int level(TreeNode* root){
        if(root == NULL) return 0;
        return 1+max(level(root->right),level(root->left));
    }
    void Nthlevel(TreeNode* root,int levels,int reql,vector<int>& v){
        if(root == NULL) return;
        if(levels==reql){
            v.push_back(root->val);
            return;
        }
        Nthlevel(root->left,levels+1,reql,v); // call1
        Nthlevel(root->right,levels+1,reql,v); // call2  
    }
    void levelordertraversal(TreeNode* root,vector<vector<int>>& ans){
        int n = level(root);
        for(int i=1;i<=n;i++){
            vector<int>v;
            Nthlevel(root,1,i,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelordertraversal(root,ans);
        return ans;

    }
};