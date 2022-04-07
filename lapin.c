#include <stdio.h>
#include<string.h>
#define MAX 1001
int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
	    char str[MAX];
	    scanf("%s",str);
        int n=strlen(str),h;
        int count[36]={0},pos;
        h=n/2;
        if(n%2!=0){
		    str[n]=str[n/2];
		    h++;
	    }
        for (int i=0; i<h; i++){
            pos=(int)str[i]-97;
            // printf("1)pos=%d\n",pos);
            count[pos]++;
            pos=(int)str[n-1-i]-97;
            // printf("1)pos=%d\n",pos);
            count[pos]--;
        }
        int flag=0;
        for (int i=0;i<n;i++){
            if(count[i]!=0){
                printf("NO\n");
                flag=1;
                break;
            }
        }
        if (flag==0){
            printf("YES\n");
        }
	}
	return 0;
}

