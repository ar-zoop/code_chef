#include<stdio.h>
//prototyping
void push(char);
int pop();

//global variables
char stack[1000000];
char str[1000000];
int top=-1;

int main(){
	int t;
    while(t--){
        int i,f=1,count=0;
        char x;
        gets(str);
        for (i=0;str[i]!='\0';i++){
            if (str[i]=='<'){
                push(str[i]);
            }
            else if(str[i]=='>'){
                x=pop();
                if (x!='<'){
                    f=0;
                }
                else{
                    count++;
                }
            }

        }
        
    }
    //checking if balanced or unbalanced	
      
    
	return 0;
}

void push(char x){
		
		top++;
		stack[top]=x;
	
	
}

int pop(){
	char x;
	x=stack[top];
	top--;
	return x;
}





