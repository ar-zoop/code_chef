#include <iostream>
using namespace std;

int main(){
    int n=5;
    int prev2=0;
    int prev=1;
    for (int i=2;i<=n;i++){
        int curi=prev+prev2;
        prev2=prev;
        prev=curi;
    }
    cout<<prev<<endl;
    return 0;
}