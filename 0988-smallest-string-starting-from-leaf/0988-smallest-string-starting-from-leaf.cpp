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
void dfs(TreeNode* root,string& word,map<string,int>& dict){
    word+=(root->val+'a');
if(root->left==nullptr && root->right==nullptr) {
string temp=word;
reverse(temp.begin(),temp.end());
dict[temp]++;
}
if(root->left!=nullptr) dfs(root->left,word,dict);
if(root->right!=nullptr) dfs(root->right,word,dict);
word.pop_back();
}
    string smallestFromLeaf(TreeNode* root) {
        map<string,int>dict;
        string word="";
         dfs(root,word,dict);
        string ans=(*(dict.begin())).first;
        return ans;
    }
};