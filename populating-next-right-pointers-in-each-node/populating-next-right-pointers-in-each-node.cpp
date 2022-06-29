/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) {
            return root;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node* prev=NULL;
        while(!q.empty()) {
            Node* n=q.front();
            q.pop();
            
            if(q.size()==0) {
                break;
            }
            
            if(n==NULL) {
                q.push(NULL);
                prev->next=NULL;
                prev=NULL;
                continue;
            }
            
            if(prev!=NULL) {
                prev->next=n;
            }
            prev=n;
            if(n->left) {
                q.push(n->left);
            }
            if(n->right) {
                q.push(n->right);
            }
        }
        return root;
    }
};