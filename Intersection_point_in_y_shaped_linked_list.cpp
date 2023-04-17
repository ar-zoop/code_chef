//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    /*
    map<Node*, bool> mpp;
    Node* pt= head1;
    while(pt!=NULL){
        mpp[pt]=1;
        pt=pt->next;
    }
    pt=head2;
    while(pt!=NULL){
        if(mpp.find(pt)!=mpp.end()){
            return pt->data;
        }
        pt=pt->next;
    }
    return -1;
    */
    int len1=0, len2=0, diff;
    Node *a= head1;
    while(a!=NULL){
        len1++;
        a=a->next;
    }
    a=head2;
    while(a!=NULL){
        len2++;
        a=a->next;
    }
    if(len1>len2){
        diff=len1-len2;
        a=head1;
        while(diff--){
            a=a->next;
        }
        Node *b=head2;
        while( a!=NULL && b!=NULL){
            if(a==b){
                return a->data;
            }
            a=a->next;
            b=b->next;
        }
    }
    else{
        diff=len2-len1;
        a=head2;
        while(diff--){
            a=a->next;
        }
        Node *b=head1;
        while(a!=NULL && b!=NULL ){
            if(a==b){
                return a->data;
            }
            a=a->next;
            b=b->next;
        }
    }
    return -1;
}

















