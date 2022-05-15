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

struct p {
    TreeNode* h;
    TreeNode* t;
};

class Solution {
public:
    
    TreeNode* rec(TreeNode* root, TreeNode* att) {
        if(root==NULL) {
            return att;
        }
        // cout<<root->val<<endl;
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        
        TreeNode* tmp= r!=NULL ? r : att;
        TreeNode* lh=rec(l, tmp);
        root->left=NULL;
        root->right=lh;
        r=rec(r, att);
        return root;
    }
    
    void flatten(TreeNode* root) {
        rec(root,NULL);
    }
};