/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root, int& ans){
        if(!root)   return NULL;

        TreeNode* leftTree = helper(root->left, ans);
        TreeNode* rightTree = helper(root->right, ans);

        if(leftTree){
            root->val += leftTree->val - 1;
            ans += abs(leftTree->val - 1);
            leftTree->val == 1;
        }
        if(rightTree){
            root->val += rightTree->val - 1;
            ans += abs(rightTree->val - 1);
            rightTree->val == 1;
        }

        return root;
    }
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};