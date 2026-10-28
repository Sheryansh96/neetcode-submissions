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
    int maxsum(TreeNode* root, int& maxans){
        if(root == nullptr) return 0;
        int leftsum = max(maxsum(root->left, maxans), 0);
        int rightsum = max(maxsum(root->right, maxans), 0);
        maxans = max(maxans, root->val+leftsum+rightsum);
        return root->val + max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxans = INT_MIN;
        maxsum(root, maxans);
        return maxans;
    }
};
