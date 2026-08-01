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
    bool isValidBST(TreeNode* root) {
        return Valid(root, LONG_MIN, LONG_MAX);
    }
private:
    bool Valid(TreeNode* root, long min, long max){
        if (root==nullptr) return true;
        if (root->val>=max || root->val<=min) return false;
        return Valid(root->left, min, root->val) && Valid(root->right, root->val, max);
    }
};
