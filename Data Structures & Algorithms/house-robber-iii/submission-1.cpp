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
    unordered_map<TreeNode*, int> mp[2];
    int helper(int sum, TreeNode* root, int take){
        if(root == nullptr){
            return 0;
        }
        if(mp[take].find(root) != mp[take].end()) return mp[take][root];
        int ans = 0;
        int a1=0,a2=0,a3=0,a4=0,a5=0;
        if(take == 1){
            a1 = helper(sum, root->left, 0);
            a2 = helper(sum, root->right, 0);
        }
        a3 = helper(sum, root->left, 1);
        a4 = helper(sum, root->right, 1);
        if(take == 1){
            a5 = root->val;
        }
        ans = max((a1+a2+a5) , (a3+a4));
        mp[take][root] = ans;
        return ans;
    }

    int rob(TreeNode* root) {
        return helper(0, root, 1);
    }
};