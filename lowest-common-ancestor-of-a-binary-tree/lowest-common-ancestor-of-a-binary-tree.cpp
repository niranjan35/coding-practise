/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* rec(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        if(root==NULL) {
            return root;
        }
        if(root->val==n1->val) {
            return root;
        }
        if(root->val==n2->val) {
            return root;
        }
        TreeNode* l=rec(root->left,n1,n2);
        TreeNode* r=rec(root->right,n1,n2);
        if(l!=NULL && r!=NULL) {
            return root;
        }
        return l!=NULL ? l:r;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return rec(root,p,q);
    }
};