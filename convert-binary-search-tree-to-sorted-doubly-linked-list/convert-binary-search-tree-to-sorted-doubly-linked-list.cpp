/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    
    pair<Node*, Node*> rec(Node* root) {
        Node* l=root;
        Node* r=root;
        Node* root_l=NULL,root_r=NULL;
        if(root->left) {
            pair<Node*, Node*> tmp=rec(root->left);
            l=tmp.first;
            tmp.second->right=root;
            root_l=tmp.second;
        }
        if(root->right) {
            pair<Node*, Node*> tmp=rec(root->right);
            r=tmp.second;
            root->right=tmp.first;
            tmp.first->left=root;
        }
        root->left=root_l;
        return make_pair(l,r);
    }
    
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) {
            return NULL;
        }
        pair<Node*,Node*> p= rec(root);
        p.first->left=p.second;
        p.second->right=p.first;
        // cout<<p.first->left->val<<" "<<p.second->right->val<<endl;
        return p.first;
    }
};