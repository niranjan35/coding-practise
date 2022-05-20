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
    int tmp,tmp1;
    vector<vector<int>> ans;
    void traverse(TreeNode* root, int val) {
        if(root==NULL) {
            return;
        }
        if(val<tmp) {
            tmp=val;
        }
        if(val>tmp1) {
            tmp1=val;
        }
        if(root->left) {
            traverse(root->left,val-1);
        }
        if(root->right) {
            traverse(root->right,val+1);
        }
    }
    
    void rec(TreeNode* root, int val) {
        // if(root==NULL) {
        //     return;
        // }
        // cout<<"val = "<<val<<" root = "<<root->val<<endl;
        // ans[val].push_back(root->val);
        // if(root->left) {
        //     rec(root->left,val-1);
        // }
        // if(root->right) {
        //     rec(root->right,val+1);
        // }
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root,val));
        while(!q.empty()) {
            pair<TreeNode*,int> p=q.front();
            q.pop();
            // cout<<p.second<<" "<<p.first->val<<endl;
            ans[p.second].push_back(p.first->val);
            if(p.first->left) {
                q.push(make_pair(p.first->left,p.second-1));
            }
            if(p.first->right) {
                q.push(make_pair(p.first->right,p.second+1));
            }
        }
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        tmp=0;tmp1=0;
        traverse(root,0);
        cout<<tmp<<" "<<tmp1<<endl;
        if(tmp==0 && tmp1==0) {
            if(root==NULL) {
                return ans;
            }
        }
        for(int i=tmp;i<=tmp1;i++) {
            vector<int> v;
            ans.push_back(v);
        }
        rec(root,-1*tmp);
        return ans;
    }
};