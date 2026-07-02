class Solution {
public:
    bool f(TreeNode* root, int targetSum,int sum){
        if (root == NULL) return false;
        int currentSum = sum + root->val;
        if (root->left == NULL && root->right == NULL){
            return targetSum == currentSum; 
        }
        return f(root->left, targetSum, currentSum) || 
               f(root->right, targetSum, currentSum);
    }
        
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return f(root,targetSum,0);
    }
};