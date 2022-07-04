class Trie {
public:
    struct TrieNode {
        bool isEnd;
        vector<TrieNode*> links;
        
        TrieNode() {
            isEnd=false;
            for(int i=0;i<26;i++) {
                links.push_back(NULL);
            }
        }
    };
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string w) {
        TrieNode* curr=root;
        for(int i=0;i<w.size();i++) {
            if(curr->links[w[i]-'a']==NULL) {
                curr->links[w[i]-'a']=new TrieNode();
            }
            curr=curr->links[w[i]-'a'];
        }
        curr->isEnd=true;
    }
    
    bool search(string w) {
        TrieNode* curr=root;
        for(int i=0;i<w.size();i++) {
            if(curr->links[w[i]-'a']==NULL) {
                return false;
            }
            curr=curr->links[w[i]-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string w) {
        TrieNode* curr=root;
        for(int i=0;i<w.size();i++) {
            if(curr->links[w[i]-'a']==NULL) {
                return false;
            }
            curr=curr->links[w[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */