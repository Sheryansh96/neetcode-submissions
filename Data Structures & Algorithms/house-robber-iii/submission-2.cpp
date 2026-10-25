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
    pair<int,int> helper(TreeNode* root){
        if(root == nullptr){
            return {0,0};
        }
        auto [ls,lr] = helper(root->left);
        auto [rs,rr] = helper(root->right);
        int rob = root->val + ls + rs;
        int skip = max(ls,lr) + max(rs,rr);
        return {skip, rob};
    }
    int rob(TreeNode* root) {
        auto [s,r] = helper(root);
        return max(s,r);
    }
};