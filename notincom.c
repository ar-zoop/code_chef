#include <stdio.h>
#include <stdlib.h>
//creation of bs tree
int insert();
int search(int);
typedef struct bst_node{
	struct bst_node *left;
	int data;	
	struct bst_node *right;
}node;

node *temp,*p,*q,*root;
int a[1000001];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        // a[1000001]={0};
	    insert();	
        root=NULL;
    // printf("%d\n",count);
    }
	return 0;
}

int insert(){
	
	// printf("Enter no. of nodes in tree: ") ;
        int n,m;
        scanf("%d%d", &n,&m);
    
        for (int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        /*
        while(n--){
            temp=(node*)malloc(sizeof(node));
            // printf("Enter data: ");
            scanf("%d", &temp->data);
            temp->right=NULL;
            temp->left=NULL;
            if(roota==NULL){
                roota=temp;
            }
            else{
                p=roota;	
                while(p!=NULL){
                if (temp->data>p->data){
                    q=p;
                    p=p->right;
                }
                else{
                    q=p;
                    p=p->left;
                }
        
                }
                if (temp->data>q->data){
                    q->right=temp;
                }
                else {
                    q->left=temp;
                }
            }
        
        }
        */
        while(m--){
            temp=(node*)malloc(sizeof(node));
            // printf("Enter data: ");
            scanf("%d", &temp->data);
            temp->right=NULL;
            temp->left=NULL;
            if(root==NULL){
                root=temp;
            }
            else{
                p=root;	
                while(p!=NULL){
                if (temp->data>p->data){
                    q=p;
                    p=p->right;
                }
                else{
                    q=p;
                    p=p->left;
                }
        
                }
                if (temp->data>q->data){
                    q->right=temp;
                }
                else {
                    q->left=temp;
                }
            }
	
    	}
        int count=search(n);
        printf("%d\n",count);
    }
 


int search(int n){
	
	int num;
    int count=0;
    for (int i=0;i<n;i++){	
        num=a[i];
        p=root;
        
        if (p==NULL){
            ;
        }
        else{
        
            while(p!=NULL){
                if (p->data==num){
                    // printf("num=%d\n",num);
                //element found condition
                    count++;
                    break;
                }
                else if (p->data > num){
                    p=p->left;
                }
                else {
                    p=p->right;
                }	
            
            }
        
        
        }
        
    }
    return count;
}
