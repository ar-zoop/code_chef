#include<stdio.h>
void verify(char *,int);
int main(){
	int t,n,count;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		char s[n];
		int a[100]={0};
		scanf("%s",s);
		count=0;
		for (int i=1;s[i]!='\0';i++){
			if(s[i]<s[i-1])
				a[count++]=i;
		}
		
		if (count==0)
			printf("YES\n");
		
		else if (count==1){
			int i=a[0];
			//swap
			char temp=s[i];
			s[i]=s[i-1];
			s[i-1]=temp;
			//verify
// 			printf("sup");
			verify(s,n);
		}
		
		else if (count==2){
			int i=a[0];
			int j=a[1];
			//swap
			char temp=s[i-1];
			s[i-1]=s[j];
			s[j]=temp;
			//verify
// 			printf("hello");
			verify(s,n);
		}
		
		else{
		    printf("NO\n");
		}
	}
	return 0;
}

void verify(char *s,int n){
    // printf("hi");
	for (int i=1;s[i]!='\0';i++){
		if (s[i]<s[i-1]){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}
