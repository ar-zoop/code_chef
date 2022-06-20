//tabulation is the way to remove recursion
//you write the recurrence relation in terms of memoized array
 
#include <iostream>
using namespace std;

int F[51]; // the array that stores all the results of multiplications 
// int fib(int n){
//     if(n<=1)return n;
//     if (F[n]!=-1) return F[n];
//     F[n]= fib(n-1)+fib(n-2);
//     return F[n];
// }

int main(){
    int n=5, result;
    F[0]=0;
    F[1]=1;
    for (int i=2;i<=n;i++){ //we strat from 2 becase 0 and 1 are never executed
        F[i]=F[i-1]+F[i-2];
    }
    cout<<0<<" "<<1<<" ";
    for(int i=2;i<=n;i++){
        cout<<F[i]<<" ";
    }
    return 0;
}