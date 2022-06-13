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
    ListNode* removeNthFromEnd(ListNode* head, int nn) {
        ListNode* n=head;
        int s=0;
        if(n!=NULL) {
            s=1;
        }
        while(n->next!=NULL) {
            s++;
            n=n->next;
        }
        int x=s-nn+1;
        s=0;
        n=head;
        ListNode* prev=NULL;
        if(n!=NULL) {
            s=1;
        }
        while(s<x) {
            s++;
            prev=n;
            n=n->next;
        }
        if(prev!=NULL) {
            prev->next=n->next;
        }
        if(prev==NULL) {
            return head->next;
        }
        return head;
    }
};