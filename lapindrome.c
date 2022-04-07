#include<stdio.h>
#include<string.h>

int lapindrome(char[]);

void str_sort(char*[]);

int main(){
	
	int t,i;
	char s1[10]="arzoo",*p;
	p=&s1[0];
	sort_str(p);
	printf("%s",s1);
	printf("%s\n",s2);
	scanf("%d", &t);
	for (i=0;i<t;i++){
		scanf("%s",&s1);
		if (lapindrome(s1))
			printf("YES");
		else
			printf("NO");
	}
	return 0;
}

int lapindrome(char s[]){
	int n=strlen(s),x,d;
	char arr1[500],arr2[500];
	if (n%2==0){
		x=n/2;
		strncpy(arr1, s, x);
		strncpy(arr2, s+x, x);
		strcpy(arr1, sort_str(arr1));
		strcpy(arr2,sort_str(arr2));
		d=stricmp(arr1,arr2);
		if (d==0)
			return 1;
	}
	return 0;
}

void sort_str(char* str[]){
	int i=0,j;
	char temp;
	while(str[i]!='\0'){
		j=i+1;
		temp=str[i];
		while(str[j]<str[j-1] && j>0){
			str[j]=str[j-1];
		}
		str[j+1]=temp;
		i++;
	}
	printf("%s",str);
	return str;
}
