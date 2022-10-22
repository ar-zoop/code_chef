/*
Link to the problem:
https://www.geeksforgeeks.org/find-common-element-rows-row-wise-sorted-matrix/
*/

#include <bits/stdc++.h>
using namespace std;

int findCommon(vector<vector<int>>&matrix, int mat_size, int mat_0_size){
    map<int,int> row_one;
    for(int j=0; j<mat_0_size;j++){
        row_one[matrix[0][j]]=1;
    }
    for(int i=1; i<mat_size;i++){
        for(int j=0;j<mat_0_size;j++){
           if(row_one.find(matrix[i][j])!=row_one.end())
                row_one[matrix[i][j]]++;
        }
    }
    for(auto x:row_one){
        // cout<<x.second<<endl;
        if(x.second == mat_0_size-1){
            return x.first;
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> matrix={ {1, 2, 3, 4, 5},
                    {2, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9},
                  };
    cout<< findCommon(matrix, matrix.size(), matrix[0].size());
    return 0;
}