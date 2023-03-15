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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==NULL) return list2;
        if(list2==NULL)return list1;
        ListNode *p=list1, *r=list2, *pNext=list1->next, *rNext=list2->next;
        while(pNext!=NULL && rNext!=NULL){
            if(p->val <= r->val){
                if(pNext->val <= r->val){
                    p->next=pNext;
                }
                else{
                    p->next=r;
                }
                p=pNext;
                pNext=p->next;
            }
            else{
                if(p->val <= rNext->val){
                    r->next=p;
                }
                else{
                    r->next=rNext;
                }
                r=rNext;
                rNext=r->next;
            }
        }
        int flag=1;
        while(rNext!=NULL){
            if(p->val <= r->val){
                p->next=r;
                flag=0;
                break;
            }
            else{
                if(p->val<=rNext->val){
                    r->next=p;
                    p->next=rNext;
                    flag=0;
                    break;
                }
                else{
                    r->next=rNext;
                    r=rNext;
                    rNext=r->next;
                }
            }
        }

        while(pNext!=NULL){
             if(r->val < p->val){
                r->next=p;
                flag=0;
                break;
            }
            else{
                if(r->val<=pNext->val){
                    p->next=r;
                    r->next=pNext;
                    flag=0;
                    break;
                }
                else{
                    p->next=pNext;
                    p=pNext;
                    pNext=p->next;
                }
            }
        }

        if(flag){
            if(p->val <= r->val){
                p->next=r;
            }
            else{
                r->next=p;
            }
        }

        if(list1->val <= list2->val) return list1;
        return list2;
    } 
};