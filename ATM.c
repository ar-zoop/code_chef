#include <stdio.h>
void main(){
	int x;
	float y;
	scanf("%d %f", &x, &y);
	
	y=y-0.50;

	if(x%5==0 && x<=y){
		y=y-x;
		printf("%.2f", y);
		
	}
	else{
		printf("%.2f", y+0.50);
		
	}
}
