class MRUQueue {
public:
    
    struct Node {
        int v;
        Node* l;
        Node* r;
    };
    
    Node* newNode(int val) {
        Node* n=new Node();
        n->v=val;
        n->l=NULL;
        n->r=NULL;
        return n;
    }
    
    Node* s;
    Node* e;
    
    void insertAtEnd(Node* n) {
        // cout<<n->v<<endl;
        Node* tmp=e->l;
        tmp->r=n;
        n->l=tmp;
        n->r=e;
        e->l=n;
    }
    
    MRUQueue(int n) {
        s=newNode(-1);
        e=newNode(-1);
        s->r=e;
        e->l=s;
        
        for(int i=1;i<=n;i++) {
            Node* n=newNode(i);
            insertAtEnd(n);
        }
    }
    
    int fetch(int k) {
        // cout<<"fetch  = "<<k<<endl;
        Node* curr=s;
        for(int i=1;i<=k;i++) {
            curr=curr->r;
        }
        curr->l->r=curr->r;
        curr->r->l=curr->l;
        curr->l=NULL;
        curr->r=NULL;
        
        insertAtEnd(curr);
        
        return curr->v;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */