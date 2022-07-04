class Solution {
public:
    
    struct TrieNode {
        vector<TrieNode*> links;
        bool end;
        TrieNode() {
            for(int i=0;i<26;i++) {
                links.push_back(NULL);
            }
            end=false;
        }
    };
    
    TrieNode* root;
    int m,n;
    vector<string> ans;
    int xx[4]={1,0,-1,0};
    int yy[4]={0,1,0,-1};
    
    void insert(TrieNode* root, string w) {
        TrieNode* curr=root;
        for(int i=0;i<w.size();i++) {
            if(curr->links[w[i]-'a']==NULL) {
                curr->links[w[i]-'a']=new TrieNode();
            }
            curr=curr->links[w[i]-'a'];
        }
        curr->end=true;
    }
    
    bool search(TrieNode* root, string w) {
        TrieNode* curr=root;
        for(int i=0;i<w.size();i++) {
            if(curr->links[w[i]-'a']==NULL) {
                return false;
            }
            curr=curr->links[w[i]-'a'];
        }
        return curr->end;
    }
    
    bool prefix(TrieNode* root, string w) {
        TrieNode* curr=root;
        for(int i=0;i<w.size();i++) {
            if(curr->links[w[i]-'a']==NULL) {
                return false;
            }
            curr=curr->links[w[i]-'a'];
        }
        return true;
    }
    
    void rec(vector<vector<char>>& b, int x, int y, TrieNode* curr, string s) {
        if(x<0 || x>=m || y<0 || y>=n || curr==NULL || b[x][y]=='#' || curr->links[b[x][y]-'a']==NULL) {
            return;
        }
        char c=b[x][y];
        string new_s=s+string(1,c);
        curr=curr->links[b[x][y]-'a'];
        if(curr->end) {
            // cout<<"x = "<<x<<" y = "<<y<<" s = "<<s<<endl;
            // cout<<"pushing "<<new_s<<endl;
            ans.push_back(new_s);
            curr->end=false;
        }
        b[x][y]='#';
        for(int i=0;i<4;i++) {
            // cout<<"calls "<<new_s+string(1,c)<<endl;
            rec(b,x+xx[i],y+yy[i],curr,new_s);
            // cout<<"callout"<<endl;
        }
        b[x][y]=c;
    }
    
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        root=new TrieNode();
        for(int i=0;i<words.size();i++) {
            insert(root,words[i]);
        }
        m=b.size();
        n=b[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                rec(b,i,j,root,"");
                // cout<<"-------------"<<endl;
            }
        }
        return ans;
    }
};