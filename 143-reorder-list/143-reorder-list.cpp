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
    void reorderList(ListNode* head) {
        int n=0;
        ListNode* curr=head;
        while(curr!=NULL) {
            n++;
            curr=curr->next;
        }
        int nn=n-(n/2)+1;
        int tmp=1;
        curr=head;
        ListNode* prev=NULL;
        // cout<<nn<<endl;
        while(tmp<nn) {
            prev=curr;
            curr=curr->next;
            tmp++;
        }
        // cout<<curr->val<<endl;
        prev->next=NULL;
        prev=NULL;
        while(curr!=NULL) {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* rev_head=prev;
        // cout<<"----"<<endl;
        // while(rev_head!=NULL) {
        //     cout<<rev_head->val<<endl;
        //     rev_head=rev_head->next;
        // }
        // cout<<head->val<<endl;
        // cout<<rev_head->val<<endl;
        ListNode* f_head=head;
        // cout<<f_head->val<<endl;
        // cout<<rev_head->val<<endl;
        while(f_head!=NULL && rev_head!=NULL) {
            ListNode* f_head_nxt=f_head->next;
            ListNode* rev_head_nxt=rev_head->next;
            f_head->next=rev_head;
            rev_head->next=f_head_nxt;
            rev_head=rev_head_nxt;
            f_head=f_head_nxt;
        }
    }
};