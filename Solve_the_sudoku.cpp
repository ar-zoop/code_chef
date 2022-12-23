//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku.
    // bool caller_function(int grid[N][N]);
    // void calc_options(vector<int>&used_map, int row, int col,int grid[N][N]);
    // bool recur(int i, int j, vector<int>&used_map, int grid[N][N], int i_max, int j_max);
    // void fill_map(int grid[N][N], vector<int>&used_map, int row, int col);
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return caller_function(grid);
    }
    
    void fill_map(int grid[N][N], vector<int>&used_map, int row, int col){
        for(int i=row; i<row+3; i++){
            for(int j=col; j<col+3; j++){
                if(grid[i][j]!=0){
                    used_map[grid[i][j]]=1;
                }
            }
        }
        return;
    }
    
    bool caller_function(int grid[N][N]){
        vector<int>used_map(9,0);
        bool flag=false;
        for(int i=0; i<9; i=i+3){
            for(int j=0; j<9; j=j+3){
                fill_map(grid, used_map, i, j);
                if(recur(i, j, used_map, grid, i+3,j+3)){
                    flag=true;
                }
                else{
                    return false;
                }
            }
        }
        return flag;
    }
    
    
    void calc_options(vector<int>&used_map, int row, int col,int grid[N][N]){
        for(int i=0; i<9; i++){
            if(grid[i][col]!=0){
                used_map[grid[i][col]]=1;
            }
        }
        for(int j=0; j<9; j++){
            if(grid[row][j]!=0){
                used_map[grid[row][j]]=1;
            }
        }
        return;
    }
    
    bool recur(int i, int j, vector<int>&used_map, int grid[N][N], int i_max, int j_max){
        if((i==i_max && j<j_max)||(j==j_max && i<i_max)) return false;
        if(i==i_max && j==j_max) return true;
        calc_options(used_map);
        for(int n=0; n<9; n++){
            if(used_map[n]==0){
                used_map[n]=1;
                recur(i+1, j, used_map, grid, i_max, j_max);
                recur(i, j+1, used_map, grid, i_max, j_max);
                used_map[n]=0;
            }
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends