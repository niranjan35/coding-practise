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
    vector<int> v;
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) {
            return v;
        }
        v.clear();
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* prev=NULL;
        while(!q.empty()) {
            TreeNode* n=q.front();
            q.pop();
            if(q.empty()) {
                if(prev!=NULL) {
                    v.push_back(prev->val);
                }
                break;
            }
            if(n==NULL) {
                q.push(NULL);
                if(prev!=NULL) {
                    v.push_back(prev->val);
                }
                prev=NULL;
                continue;
            }
            if(n->left) {
                q.push(n->left);
            }
            if(n->right) {
                q.push(n->right);
            }
            prev=n;
        }
        return v;
    }
};