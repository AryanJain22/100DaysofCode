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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> bfs;
        int curr_depth = 1;
        bfs.push(root);

        if(depth == 1) {
            TreeNode* new_tree = new TreeNode(val, root, nullptr);
            return new_tree;
        }

        while(!bfs.empty()) {
            int size = bfs.size();

            if(curr_depth == (depth-1)) {
                while(size--) {
                    TreeNode* curr = bfs.front();
                    if(curr->left) {
                        TreeNode* left = curr->left;
                        curr->left = new TreeNode(val);
                        curr->left->left = left;
                    }
                    else curr->left = new TreeNode(val);

                    if(curr->right) {
                        TreeNode* right = curr->right;
                        curr->right = new TreeNode(val);
                        curr->right->right = right;
                    }
                    else curr->right = new TreeNode(val);
                    bfs.pop();
                }
                return root;
            }

            else {
                while(size--) {
                    TreeNode* curr = bfs.front();
                    if(curr->left) bfs.push(curr->left);
                    if(curr->right) bfs.push(curr->right);
                    bfs.pop();
                }
                curr_depth++;
            }
        }

        return root;
    }
};