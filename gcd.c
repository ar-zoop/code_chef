#include <stdio.h>
int gcd(int,int);
int main(){
    int a,b,c;
    printf("Enter numbers you want to find gcd of:");
    scanf("%d %d",&a,&b);
    c= gcd(a,b);
    printf("%d",c);
}
int gcd(int a, int b){
    if(b>a) gcd(b,a);
    if (b==0) return a;
    gcd(b,a%b);

}