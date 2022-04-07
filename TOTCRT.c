#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char s[9];
    long long int c;
} solution;
int comps(const void* p, const void* q)
{
    return strcmp(((solution*)p)->s, ((solution*)q)->s);
}
int compc(const void* p, const void* q)
{
    return ((solution*)p)->c<((solution*)q)->c?-1:1;
}
int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
	    int n, i, j;
	    scanf("%d", &n);
	    solution sol[3*n];
	    for(i=0; i<3*n; i++) 
			scanf("%s %lld", &sol[i].s, &sol[i].c);
	    qsort(sol, 3*n, sizeof(solution), comps);
	    for(i=j=1; i<3*n; i++)
	        if(strcmp(sol[i-1].s, sol[i].s))
	        {
	            strcpy(sol[j].s, sol[i].s);
	            sol[j++].c = sol[i].c;
	        }
	        else sol[j-1].c+=sol[i].c;
	    qsort(sol, j, sizeof(solution), compc);
	    for(i=0; i<j; i++) printf("%lld ", sol[i].c);
	    printf("\n");
	}
    return 0;
}
