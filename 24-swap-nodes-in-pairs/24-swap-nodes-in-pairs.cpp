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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr=head;
        ListNode* nxt;
        ListNode* prev=NULL;
        ListNode* ret_head=NULL;
        if(head==NULL) {
            return head;
        }
        while(curr!=NULL && curr->next!=NULL) {
            nxt=curr->next;
            curr->next=nxt->next;
            nxt->next=curr;
            if(prev!=NULL) {
                prev->next=nxt;
            }
            if(ret_head==NULL) {
                ret_head=nxt;
            }
            prev=curr;
            curr=curr->next;
        }
        if(ret_head==NULL) {
            return head;
        }
        return ret_head;
    }
};