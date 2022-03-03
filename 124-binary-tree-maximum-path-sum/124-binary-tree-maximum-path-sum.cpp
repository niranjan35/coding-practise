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

struct Node {
    int re; // root ending, means ends at root :P 
    int rne; // root not endoing. means not ending at root.
};

Node* newNode(int re, int rne) {
    Node* n=new Node();
    n->re=re;
    n->rne=rne;
    return n;
}

class Solution {
public:
    int ans;
    int maxPathSum(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        ans=root->val;
        rec(root);
        return ans;
    }
    
    Node* rec(TreeNode* root) {
        if(root==NULL) {
            return NULL;
        }
        int tmp=root->val;
        int re=root->val;
        int rne=-2147483648;
        Node* l,*r;
        if(root->left) {
            l=rec(root->left);
            tmp=max(l->re,tmp);
            tmp=max(l->re+root->val,tmp);
            tmp=max(l->rne,tmp);
            re=max(re,l->re+root->val);
            rne=max(rne,l->re);
            rne=max(rne,l->rne);
        }
        if(root->right) {
            r=rec(root->right);
            tmp=max(r->re,tmp);
            tmp=max(r->re+root->val,tmp);
            tmp=max(r->rne,tmp);
            re=max(re,r->re+root->val);
            rne=max(rne,r->re);
            rne=max(rne,r->rne);
        }
        if(root->left && root->right) {
            tmp=max(tmp,l->re+root->val+r->re);
        }
        if(tmp>ans) {
            ans=tmp;
        }
        return newNode(re,rne);
    }
};