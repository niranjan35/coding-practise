class LRUCache {
public:
    
    struct Node {
        int key;
        int val;
        Node* left;
        Node* right;
    };
    
    Node* newNode(int key,int val) {
        Node* n=new Node();
        n->key=key;
        n->val=val;
        n->left=NULL;
        n->right=NULL;
        return n;
    }
    
    Node* newNode(int key, int val, Node* l, Node* r) {
        Node* n=new Node();
        n->key=key;
        n->val=val;
        n->left=l;
        n->right=r;
        return n;
    }
    
    int c,sz;
    vector<Node*> vect;
    Node* s;
    Node* e;
    
    LRUCache(int capacity) {
        s=newNode(-1,-1);
        e=newNode(-1,-1);
        s->right=e;
        e->left=s;
        for(int i=0;i<10020;i++) {
            vect.push_back(NULL);
        }
        sz=0;
        c=capacity;
    }
    
    void moveToFront(int k) {
        Node* n=vect[k];
        
        if(n->right) {
            n->right->left=n->left;
        }
        if(n->left) {
            n->left->right=n->right;
        }
        n->left=NULL;
        n->right=NULL;
        
        n->right=s->right;
        n->right->left=n;
        s->right=n;
        n->left=s;
    }
    
    void removeFromBack() {
        Node* n=e->left;
        if(n->val==-1) {
            return;
        }
        if(n->left) {
            n->left->right=n->right;
        }
        if(n->right) {
            n->right->left=n->left;
        }
        vect[n->key]=NULL;
        sz--;
    }
    
    int get(int k) {
        if(vect[k]==NULL) {
            return -1;
        }
        
        moveToFront(k);
        
        return vect[k]->val;
    }
    
    void put(int k, int v) {
        if(vect[k]==NULL) {
            vect[k]=newNode(k,v);
            sz++;
        }
        vect[k]->val=v;
        moveToFront(k);
        if(sz>c) {
            removeFromBack();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */