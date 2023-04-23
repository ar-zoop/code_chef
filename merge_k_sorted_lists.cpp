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
    ListNode* merge(ListNode *left, ListNode *right){
        ListNode *head, *prev=NULL;
        if(left->val <= right->val) head= left;
        else head=right;
        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                if(prev!=NULL)
                    prev->next=left;
                prev=left;
                left=left->next;
            }
            else{
                if(prev!=NULL)
                    prev->next=right;
                prev=right;
                right=right->next;
            }
        
        }
        if(left!=NULL){
            prev->next=left;
        }
        if(right!=NULL){
            prev->next=right;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        if(k==1) return lists[0];
        int j=0;
        for(int i=1; i<k; i++){
            if(lists[j]==NULL && lists[i]!=NULL){
                j=i;
                // continue;
            }
            else if(lists[i]!=NULL && lists[j]!=NULL && i!=j){
                lists[i]=merge(lists[i], lists[j]);
                j=i;
            }        

          
        }
        return lists[j];
    }
};