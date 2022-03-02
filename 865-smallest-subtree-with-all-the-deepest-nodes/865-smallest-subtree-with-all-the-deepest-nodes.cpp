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
    TreeNode* ans=NULL;
    int dmax=-1;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        rec(root,0);
        return ans;
    }
    
    int rec(TreeNode* root, int dep) {
        int dl=dep;
        if(root->left) {
            dl=rec(root->left,dep+1);
        }
        int dr=dep;
        if(root->right) {
            dr=rec(root->right,dep+1);
        }
        // cout<<"root = "<<root->val<<" "<<dl<<" "<<dr<<endl;
        if(dl==dr && dl>=dmax) {
            ans=root;
            dmax=dl;
        }
        return max(dl,dr);
    }
};