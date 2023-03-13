/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //trying the tortoise-hare pointer method
        if(head==NULL || head->next ==NULL) return false;
        ListNode *tort=head, *hare=head->next;
        while(tort!=hare){
            if(tort->next== NULL || hare->next==NULL || hare->next->next==NULL) return false;
            tort=tort->next;
            hare=hare->next->next;
        }
        return true;
    }
};