#include <bits/stdc++.h>
using  namespace std;
int main(){
    int n,m;
    m = 5, n = 5;
    char matrix[m][n];
    int left=0, right=n-1,top=0, bottom=m-1;
    char toPut='X';
    while(bottom>=top && left<=right){
            for(int i=left; i<=right;i++){
                matrix[top][i]=toPut;
                
            }
            top++;
            if(bottom>=top && left<=right)
                {for(int i=top; i<=bottom;i++){
                    matrix[i][right]=toPut;
                    
                }}
            right--;
            if(bottom>=top && left<=right)
                {for(int i=right;i>=left;i--){
                    matrix[bottom][i]=toPut;
                }}
            bottom--;
            if(bottom>=top && left<=right)
            {for(int i=bottom; i>=top;i--){
                matrix[i][left]=toPut;
            }}
            left++;
            if(toPut=='X') toPut='0';
            else toPut='X';
    }
    //printing the matrix
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
    return 0;
} 