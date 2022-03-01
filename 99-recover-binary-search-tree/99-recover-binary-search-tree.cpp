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
    TreeNode* prev=NULL,*n1=NULL,*n2=NULL,*tmp=NULL;
    
    void recoverTree(TreeNode* root) {
        rec(root);
        int tmp1=n1->val;
        if(n2) {
            n1->val=n2->val;
            n2->val=tmp1;
        }
        else {
            n1->val=tmp->val;
            tmp->val=tmp1;
        }
    }
    
    void rec(TreeNode* root) {
        if(root==NULL) {
            return;
        }
        if(root->left) {
            rec(root->left);
        }
        if(prev!=NULL && prev->val>root->val) {
            if(n1==NULL) {
                n1=prev;
                tmp=root;
            }
            else {
                n2=root;
            }
        }
        prev=root;
        if(root->right) {
            rec(root->right);
        }
    }
};