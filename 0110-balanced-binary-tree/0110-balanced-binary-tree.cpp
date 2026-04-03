class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+ max(levels(root->right),levels(root->left));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int n = abs(levels(root->left)-levels(root->right));
        if(n>1) return false;
        return isBalanced(root->right) && isBalanced(root->left);
    }
};