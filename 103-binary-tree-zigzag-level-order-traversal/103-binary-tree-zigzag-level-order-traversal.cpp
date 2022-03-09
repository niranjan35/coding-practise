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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL) {
            return v;
        }
        vector<int> tmp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool dir=true;
        while(!q.empty()) {
            TreeNode* n=q.front();
            q.pop();
            if(n==NULL) {
                // tmp.push_back(n->val);
                if(!dir) {
                    reverse(tmp.begin(),tmp.end());
                }
                dir=!dir;
                v.push_back(tmp);
                tmp.clear();
            }
            if(n==NULL && q.empty()) {
                break;
            }
            if(n==NULL) {
                q.push(NULL);
                continue;
            }
            tmp.push_back(n->val);
            if(n->left) {
                q.push(n->left);
            }
            if(n->right) {
                q.push(n->right);
            }
        }
        return v;
    }
};