/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    bool vis[110];
    map<int,Node*> mp;
    Node* dfs(Node* node) {
        if(node==NULL) {
            return NULL;
        }
        if(vis[node->val]) {
            return mp[node->val];
        }
        Node* node_clone=new Node(node->val);
        vis[node->val]=1;
        mp[node->val]=node_clone;
        for(int i=0;i<node->neighbors.size();i++) {
            if(!vis[node->neighbors[i]->val]) {
                Node* node_clone_neigh=dfs(node->neighbors[i]);
                node_clone->neighbors.push_back(node_clone_neigh);
            }
            else {
                node_clone->neighbors.push_back(mp[node->neighbors[i]->val]);
            }
        }
        return node_clone;
    }
    
    Node* cloneGraph(Node* node) {
        memset(vis,0,sizeof(vis));
        Node* x= dfs(node);
        return x;
    }
};