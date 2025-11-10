#include<bits/stdc++.h>
using namespace std;

void printboard(const vector<vector<int>> &board, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(const vector<vector<int>> &board,int row,int col,int n){
    for(int i=0;i<row;i++){ //Same Column
        if(board[i][col]==1){
            return false;
        }
    }
    
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){ //Moves diagonally up-left to detect any conflict.
        if(board[i][j]==1){
            return false;
        }
    }
    
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){ //Moves diagonally up-right to detect any conflict.
        if(board[i][j]==1){
            return false;
        }
    }
    
    return true;
}

bool solveNqueens(vector<vector<int>> &board,int n,int row){
    if(row>=n){
        return true;
    }
    
    for(int col=0;col<n;col++){ //Try placing queen in all columns of current row
        if(board[row][col]==0 && isSafe(board,row,col,n)){ //Check if it's safe to place queen
            board[row][col]=1;
            if(solveNqueens(board,n,row+1)){ 
                return true;
            }
            board[row][col]=0; //Backtracking
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the Size of Board:";
    cin>>n;
    
    vector<vector<int>> board(n,vector<int>(n,0));
    
    int firstrow, firstcol;
    cout<<"Enter the row and column for 1st queen:";
    cin>>firstrow>>firstcol;
    
    if(firstrow<0 || firstrow>=n || firstcol<0 || firstcol>=n){
        cout<<"Invalid position"<<endl;
        return 0;
    }
    board[firstrow][firstcol]=1;
    
    if(solveNqueens(board,n,firstrow+1)){
        cout<<"N Queen Solution:"<<endl;
        printboard(board,n);
    }
    else{
        cout<<"No solution exits:"<<endl;
    }
}

// Input:
// Enter the Size of Board: 4
// Enter the row and column for 1st queen: 0 1
// N Queen Solution:
// 0 1 0 0
// 0 0 0 1
// 1 0 0 0
// 0 0 1 0

// Execution Flow:

// | Step | Action | Board Snapshot |
// |------|---------|----------------|
// | 1 | Place first queen at (0,1) | `0 1 0 0` |
// | 2 | Go to row 1 → try (1,0) safe → place | `1` below diagonal is safe |
// | 3 | Go to row 2 → (2,2) safe → place |
// | 4 | Go to row 3 → (3,3) safe → place |
// | ✅ | All queens placed → print board | |

// Enter the Size of Board:4
// Enter the row and column for 1st queen:0 0
// No solution exits: