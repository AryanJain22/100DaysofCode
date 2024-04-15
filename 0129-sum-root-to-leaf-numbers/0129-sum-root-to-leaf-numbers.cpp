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
    bool isLeafNode(TreeNode *node) {
        if(nullptr == node->left && nullptr == node->right) {
            return true;
        }
        return false;
    }
    /* s_v: sum value */
    int dfs(TreeNode *node, int s_v) {
        int summation = 0;

        s_v = s_v*10 + node->val;

        if(isLeafNode(node)) {
            return s_v;
        }
        
        // recursive if left node exists
        if(node->left) {
            summation += dfs(node->left, s_v);
        }
        // recursive if right node exists
        if(node->right) {
            summation += dfs(node->right, s_v);
        }

        return summation;
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};