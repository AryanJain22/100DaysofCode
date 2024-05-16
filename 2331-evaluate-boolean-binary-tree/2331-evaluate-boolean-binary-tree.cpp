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

    bool dfs(TreeNode* r){
        if(r->val == 0 || r->val == 1){
            return r->val == 1;
        }
        else if(r->val == 2){
            return dfs(r->left) || dfs(r->right);
        }
        else if(r->val == 3){
            return dfs(r->left) && dfs(r->right);
        }

        return false;
    }

    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};