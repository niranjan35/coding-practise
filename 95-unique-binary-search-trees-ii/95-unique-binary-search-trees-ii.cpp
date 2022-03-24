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
    
    vector<TreeNode*> rec(int s, int e) {
        vector<TreeNode*> v;
        if(s>e) {
            v.push_back(NULL);
            return v;
        }
        if(s==e) {
            v.push_back(new TreeNode(s));
            return v;
        }
        for(int i=s;i<=e;i++) {
            vector<TreeNode*> l=rec(s,i-1);
            vector<TreeNode*> r=rec(i+1,e);
            for(int x=0;x<l.size();x++) {
                for(int y=0;y<r.size();y++) {
                    TreeNode* n=new TreeNode(i);
                    n->left=l[x];
                    n->right=r[y];
                    v.push_back(n);
                }
            }
        }
        return v;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return rec(1,n);
    }
};