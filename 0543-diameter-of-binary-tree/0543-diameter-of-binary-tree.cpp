class Solution {
public:
    int maxdia = 0;
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->right),levels(root->left));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        maxdia = max(levels(root->left)+levels(root->right),maxdia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxdia;
    }
};