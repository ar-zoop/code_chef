#include <stdio.h>
int grade();
int main(){
	int t,i,hard,carbon,tensile,res;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&hard);
		scanf("%d",&carbon);
		scanf("%d",&tesnile);
		res=grade(hard, carbon, tesnile);
		printf("%d", res);
	}
	return 0;
}

int grade(int h, int c, int t){
	if (h>50 && c<0.7 && t>5600)
		return 10;
	else if (h>50 && c<0.7)
		return 9;
	else if (c<0.7 && t>5600)
		return 8;
	else if(h>50 && t>5600)
		return 7;
	else if (h>50)
		return 6;
	else	
		return 5;
}
