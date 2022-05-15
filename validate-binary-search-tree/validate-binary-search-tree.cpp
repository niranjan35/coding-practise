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
    
    int cnt1,cnt2;
    
    bool rec(TreeNode* root, int mn, int mx) {
        if(root==NULL) {
            return true;
        }
        if(root->val<mn || root->val>mx) {
            return false;
        }
        
        if(root->val==INT_MAX && cnt1==0) {
            cnt1=1;
        }
        else if(root->val==INT_MIN && cnt2==0) {
            cnt2=1;
        }
        else if(root->val==mn || root->val==mx) {
            return false;
        }
        
        bool r=true,l=true;
        if(root->right) {
            r=rec(root->right,root->val,mx);
        }
        if(root->left) {
            l=rec(root->left,mn,root->val);
        }
        return l && r;
    }
    
    bool isValidBST(TreeNode* root) {
        cnt1=0;cnt2=0;
        return rec(root,INT_MIN, INT_MAX);
    }
};