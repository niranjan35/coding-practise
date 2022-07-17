/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    int indx=0;
    int nn=0;
    string ss="";
    // vector<string> v;
    int curr_indx=0;
    
    void recs(TreeNode* root) {
        if(root==NULL) {
            ss+="null,";
            return;
        }
        ss+=to_string(root->val)+",";
        recs(root->left);
        recs(root->right);
    }
    
    string serialize(TreeNode* root) {
        recs(root);
        return ss;
    }
    
    TreeNode* recd(string str) {
        int pos=0;
        if((pos=str.find(",",curr_indx))==string::npos) {
            return NULL;
        }
        // cout<<"pos = "<<pos<<" curr_indx = "<<curr_indx<<endl;
        string s=str.substr(curr_indx,pos-curr_indx);
        curr_indx=pos+1;
        if(s=="null") {
            return NULL;
        }
        // cout<<"s = "<<s<<endl;
        TreeNode* t = new TreeNode(stoi(s));
        if(curr_indx<str.size()) {
            t->left=recd(str);
        }
        if(curr_indx<str.size()) {
            t->right=recd(str);
        }
        return t;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        // string str=s;
        // int pos=0;
        // int curr_indx=0;
        // while((pos = str.find(","))!=string::npos) {
        //     string tmp = str.substr(curr_indx,pos);
        //     v.push_back(tmp);
        //     curr_indx=pos+1;
        // }
        // nn= v.size();
        return recd(s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));