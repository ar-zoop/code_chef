//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node *tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        Node *end_here=tail;
        Node *p=NULL, *q=head,*r=head->next;
        while(q!=tail->next){
            if(q->data==1) {
                p=q;
                q=r;
                if(r!=NULL)r=r->next;
                
            }
            
            else if(q->data==0 ){
                if(q==head){
                    p=q;
                    q=r;
                    if(r!=NULL) r=r->next;
                    continue;
                }
                if(q==tail){
                    if(p!=NULL){
                        tail=p;
                    }
                }
                q->next=head;
                head=q;
                if(p!=NULL){
                    p->next=r;
                }
                q=r;
                if(r!=NULL)r=r->next;
            
            }
            else {
            
                if(q==tail){
                    p=q;
                    q=r;
                    if(r!=NULL) r= r->next;
                    continue;
                }
                
                if(q==head) head=head->next;
                
                if(p!=NULL){
                    p->next=r;
                }
                q->next=tail->next;
                tail->next=q;
                // tail->next=q;
                // tail=q;
                // tail->next=NULL;
                q=r;
                if(r!=NULL) r=r->next;
            }
            
        }
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends