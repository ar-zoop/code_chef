#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

struct copy_array{
	int num;
	float freq;
};

int cmp(const void *a, const void *b) {
    
    float l = ((struct copy_array *)a)->freq;
    float r = ((struct copy_array *)b)->freq; 
    return (r - l);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int number[n];
	struct copy_array c[m];
	
	for(int i=0;i<n;i++){
		scanf("%d",&number[i]);
	}
	for(int i=0;i<m;i++){
		c[i].num=0;
		c[i].freq=-999;
	}

	//2d array including number,frequency,occurence
	int j,pos,flag;
	for(int i=1;i<=n;i++){
		j=0,pos;
		flag=0;
		
		while(c[j].freq!=-999){
			if (number[i-1]==c[j].num){
				c[j].freq++;
				flag=1;
				break;
			}
			j++;
		}
		
		pos=j;
		if(flag==0){
			c[pos].num=number[i-1];
			c[pos].freq=(1-(i/1000));
		}
	}
	
	//2d array sorting based on frequency only
	qsort(c, m, sizeof(struct copy_array), cmp);
	
	//printing based on frequency
	for (int i=0;i<m;i++){
		for (int j=0; j<(int)c[i].freq;j++){
			printf("%d ", c[i].num);
		}
	}


	return 0;
}