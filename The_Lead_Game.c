#include <stdio.h>
int main(){
	int n,s,t,w,l=0,i,l1,w1,m=0,p=0;
	scanf("%d",&n);

	for (i=0;i<n;i++){
		scanf("%d%d",&s,&t);
		m+=s;
		p+=t;
		if (m>p){
			w1=1;
			l1=m-p;
			
		}
		if(p>m){
			w1=2;
			l1=p-m;
		}
		
		if (l1>l){
				l=l1;
				w=w1;
			}
	}
	
	
	printf("%d %d",w,l);
	return 0;
}
