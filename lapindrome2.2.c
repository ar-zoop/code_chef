#include <stdio.h>
#include <string.h>

int lapin(char[]);
void restor_count();
int count[26];

int main(){
	int t,i;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		char s[1000];
		scanf("%s",s);
		if(lapin(s))
			printf("YES\n");
		else
			printf("NO\n");
		restore_count();
	}
	return 0;
}

int lapin(char s[]){
    
	int n=strlen(s),h=n/2, i,pos;	
	//ODD
	if(n%2!=0){
		s[n]=s[h];
		h++;
	}
	//EVEN
	for  (i=0;i<h;i++){
		//for first half
		pos=(int)s[i]-97;
		count[pos]+=1;
		//for second half
		pos=(int)s[i+h]-97;
		count[pos]-=1;
	}
	for(i=0;i<26;i++){
		if(count[i]!=0)
			return 0;
	}
	return 1;
	
	
}

void restore_count(){
	int i;
	for (i=0;i<26;i++)
		count[i]=0;
}
