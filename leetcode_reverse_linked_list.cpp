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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *p,
            *q,
            *r;
        p = head;
        q = head->next;
        while (q != nullptr)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        head->next = nullptr;
        head = p;
        return head;
    }
};