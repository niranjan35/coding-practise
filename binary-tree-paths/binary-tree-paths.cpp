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
    
    vector<string> v;
    
    void rec(TreeNode* root, string s, bool b) {
        if(root==NULL) {
            v.push_back(s);
            return;
        }
        string tmp=b?s+std::to_string(root->val):s+"->"+std::to_string(root->val);
        
        if(root->left==NULL && root->right==NULL) {
            v.push_back(tmp);
            return;
        }
        if(root->left) {
            rec(root->left,tmp,false);
        }
        if(root->right) {
            rec(root->right,tmp,false);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        rec(root,"",true);
        return v;
    }
};