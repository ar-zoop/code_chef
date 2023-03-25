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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head, *slow=head,*prev,*next;
        for(int i=0; i<n; i++){
            fast=fast->next;
        }
        while(fast!=NULL){
            prev=slow;
            slow=slow->next;
            next=slow->next;
            fast=fast->next;
        }
        if(slow==head){
            head=head->next;
        }
        else{
            prev->next=next;
        }
        return head;
    }
};