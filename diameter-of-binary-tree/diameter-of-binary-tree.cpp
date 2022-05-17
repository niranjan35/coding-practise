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

struct node {
    int d; // d
    int h; // h
};

class Solution {
public:
    
    node* newNode(int d, int h) {
        node* n=new node();
        n->d=d;
        n->h=h;
        return n;
    }
    
    node* rec(TreeNode* root) {
        if(root==NULL) {
            return newNode(0,0);
        }
        int l=0,r=0;
        int ans=0;
        if(!root->left && !root->right) {
            return newNode(0,0);
        }
        if(root->left) {
            node* tmp=rec(root->left);
            ans=max(ans,tmp->d);
            l=tmp->h+1;
        }
        if(root->right) {
            node* tmp=rec(root->right);
            ans=max(ans,tmp->d);
            r=tmp->h+1;
        }
        // if(l!=0) {
        //     l++;
        // }
        // if(r!=0) {
        //     r++;
        // }
        ans=max(ans,l+r);
        int h=max(l,r);
        return newNode(ans,h);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        node* n=rec(root);
        cout<<n->d<<" "<<n->h<<endl;
        return max(n->d,n->h);
    }
};