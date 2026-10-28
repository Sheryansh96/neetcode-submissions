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
    unordered_map<int,int> mp;

    TreeNode* buildTree1(vector<int>& preorder, int& pos, int start, int end){
        if(start > end) return nullptr;
        TreeNode* root = new TreeNode(preorder[pos]);
        int idx = mp[preorder[pos]];
        pos++;
        root->left = buildTree1(preorder, pos, start, idx-1);
        root->right = buildTree1(preorder, pos, idx+1, end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        int pos = 0;
        return buildTree1(preorder, pos, 0, n-1);
    }
};
