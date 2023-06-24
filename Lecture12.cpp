#include<bits/stdc++.h>
using namespace std;

// Question 1: Sudoku Solver
bool valid(char c, vector<vector<char>>& board, int row, int col){
    for(int i=0; i<9; i++){
        if(board[i][col] == c) return false;
        if(board[row][i] == c) return false;
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == c) return false;
    }
    return true;
}
bool solve(vector<vector<char>>& board, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '.') {
                for(char c='1'; c<='9'; c++){
                    if(valid(c, board, i, j)){
                        board[i][j] = c;
                        if(solve(board, n, m) == true) return true;
                        else board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size();
    solve(board, n, m);
}

int main() {
    vector<vector<char>> board = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    solveSudoku(board);
    for(auto it : board) {
        for(auto i : it) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}
