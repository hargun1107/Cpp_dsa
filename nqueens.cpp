#include <iostream>
using namespace std;

bool isSafe(int board[20][20], int row, int col, int n){
    for(int i=0;i<col;i++)
        if(board[row][i]) return false;

    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        if(board[i][j]) return false;

    for(int i=row,j=col;i<n && j>=0;i++,j--)
        if(board[i][j]) return false;

    return true;
}

void solve(int board[20][20], int col, int n, int &count){
    if(col==n){
        count++;
        cout<<"\nSolution "<<count<<":\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<(board[i][j] ? "Q " : ". ");
            cout<<endl;
        }
        return;
    }

    for(int i=0;i<n;i++){
        if(isSafe(board,i,col,n)){
            board[i][col]=1;
            solve(board,col+1,n,count);
            board[i][col]=0; // backtrack
        }
    }
}

int main(){
    cout<<"Name: Hargun Kaur Kohli"<<endl<<"Registration Number: 24BCE2198"<<endl;
    int n;
    cout<<"Enter N: ";
    cin>>n;

    if(n<4){
        cout<<"Invalid input. N must be >= 4";
        return 0;
    }

    int board[20][20]={0};
    int count=0;

    solve(board,0,n,count);

    cout<<"\nTotal solutions = "<<count;
    return 0;
}