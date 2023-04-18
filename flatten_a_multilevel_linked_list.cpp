/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // vector<int>vis(1001, 0);
        // dfs(head, vis);
        stack <Node*> stk;
        Node *ptr=head, *prev=head;
        Node *down;
        while(ptr!=NULL){
            if(ptr->child!=NULL){
                down=ptr->child;
                if(ptr->next!=NULL){
                    stk.push(ptr->next);
                    ptr->next->prev=NULL;
                }
                ptr->next=down;
                ptr->child=NULL;
                down->prev=ptr;
                prev=ptr;
                ptr=down;
            }
            else{
                prev=ptr;
                ptr=ptr->next;
            }
        }
        
        while(!stk.empty()){
            ptr=prev;
            ptr->next=stk.top();
            ptr->next->prev=ptr;
            stk.pop();
        
            while(ptr!=NULL){
                if(ptr->child!=NULL){
                    down=ptr->child;
                   if(ptr->next!=NULL){
                        stk.push(ptr->next);
                        ptr->next->prev=NULL;
                    }
                    ptr->child=NULL;
                    down->prev=ptr;
                    ptr=down;
                }
                else{
                    prev=ptr;
                    ptr=ptr->next;
                }
            }
        }
        return head;
    }
};
















