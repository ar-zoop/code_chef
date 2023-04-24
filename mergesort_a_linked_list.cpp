//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    void merge(int l, int mid, int u, vector <Node*> &vec){
        //l,mid,u are inclusive
        vector<Node*>left, right, output;
        for(int i=l; i<=mid; i++){
            left.push_back(vec[i]);
        }
        for(int i=mid+1; i<=u; i++){
            right.push_back(vec[i]);
        }
       
        int i=0, j=0;
        int n=left.size(), m=right.size();
        while(i!=n && j!=m){
            if(left[i]->data <= right[j]->data){
                output.push_back(left[i]);
                i++;
            }
            else{
                output.push_back(right[j]);
                j++;
            }
        }
        while(i!=n){
            output.push_back(left[i]);
            i++;
        }
        while( j!=m){
            output.push_back(right[j]);
            j++;
        }
        j=0;
        for(int k=l; k<=u; k++){
            vec[k]=output[j];
            j++;
        }
    }
    
    void mergesort(int l, int u, vector <Node*> &vec){
        if(l<u){
            int mid= (l+u)/2;
            mergesort(l, mid, vec);
            mergesort(mid+1, u, vec);
            
            merge(l, mid, u, vec);
        }
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        Node *ptr=head;
        vector<Node*> vec;
        while(ptr!=NULL){
            vec.push_back(ptr);
            ptr=ptr->next;
        }
        
        int l=0;
        int u=vec.size()-1;
        mergesort(l, u, vec);
        head=vec[0];
        for(int i=0;  i<u; i++){
            vec[i]->next=vec[i+1];
        }
        vec[u]->next=NULL;
        return head;
        
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends