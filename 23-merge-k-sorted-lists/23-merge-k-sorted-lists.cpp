/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    struct Node {
        ListNode* ln;
        int l_indx;
    };
    
    Node* newNode(ListNode* ln, int l_indx) {
        Node* n=new Node();
        n->ln=ln;
        n->l_indx=l_indx;
        return n;
    }
    
    struct customComp {
        bool operator() (Node* n1, Node* n2) {
            return n1->ln->val > n2->ln->val? true: false;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& vl) {
        priority_queue<Node*, vector<Node*>, customComp> q;
        int n=vl.size();
        
        for(int i=0;i<n;i++) {
            if(vl[i]!=NULL) {
                q.push(newNode(vl[i],i));
                vl[i]=vl[i]->next;
            }
        }
        
        if(q.empty()) {
            return NULL;
        }
        
        ListNode* ans=NULL;
        ListNode* h=NULL;
        
        while(!q.empty()) {
            Node* curr=q.top();
            q.pop();
            if(ans==NULL) {
                ans=curr->ln;
                h=curr->ln;
            }
            else {
                h->next=curr->ln;
            }
            if(vl[curr->l_indx]!=NULL) {
                q.push(newNode(vl[curr->l_indx],curr->l_indx));
                vl[curr->l_indx]=vl[curr->l_indx]->next;
            }
            h=curr->ln;
        }
        
        return ans;
    }
};