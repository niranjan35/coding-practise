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
    int sumNumbers(TreeNode* root) {
        return rec(root,0);
    }
    
    int rec(TreeNode* root, int val) {
        int ans=val*10+root->val;
        int l=0,r=0;
        if(root->left) {
            l=rec(root->left, ans);
        }
        if(root->right) {
            r=rec(root->right, ans);
        }
        if(l!=0||r!=0) {
            return l+r;
        }
        return ans;
    }
};