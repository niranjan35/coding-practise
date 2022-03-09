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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head,*prev=NULL,*n=NULL,*h=NULL;
        while(curr!=NULL) {
            // cout<<"inside"<<endl;
            // if(prev!=NULL && curr!=NULL) {
            //     cout<<prev->val<<" "<<curr->val<<endl;
            // }
            if(prev!=NULL && prev->val==curr->val) {
                prev=curr;
                curr=curr->next;
                continue;
            }
            if(curr->next!=NULL && curr->next->val==curr->val) {
                prev=curr;
                curr=curr->next;
                continue;
            }
            if(n==NULL) {
                h=curr;
                n=curr;
                ListNode* tmp=curr->next;
                curr->next=NULL;
                prev=curr;
                curr=tmp;
                continue;
            }
            n->next=curr;
            n=curr;
            prev=curr;
            ListNode* tmp=curr->next;
            curr->next=NULL;
            curr=tmp;
        }
        return h;
    }
};