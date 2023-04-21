//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *tail, *end_here, *curr=head, *prev=head;
        while(curr!=NULL){
            tail=curr;
            curr=curr->next;
        }
        end_here=tail;
        // cout<< tail->data<<head->data;
        curr=head, prev=head;
        while(curr!=end_here){
            // cout<<curr->data<<" ";
            if(curr->data%2!=0){
                tail->next=curr;
                tail=curr;
                if(head==curr){
                    head=head->next;
                }
                if(prev->data %2 ==0 ){
                    prev->next=curr->next;
                }
                else{
                    prev=curr;
                }
                curr=curr->next;
                tail->next=NULL;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        
        if(curr==end_here){
            if(end_here->data % 2 !=0){
                tail->next=curr;
                tail=curr;
                if(head==curr){
                    head=head->next;
                }
                if(prev->data %2 ==0 ){
                    prev->next=curr->next;
                }
                else{
                    prev=curr;
                }
                curr=curr->next;
                tail->next=NULL;
            }
        }
        
        
        // end_here->next=NULL;
        return head;
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends