#include<bits/stdc++.h>
using namespace std;

// Question 1: Word Search
bool startsHere(vector<vector<char>>& board, int x, int y, string& word, int idx) {
    if (idx == word.size()) return true;
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || 
        board[x][y] == '.' || board[x][y] != word[idx]) return false;
        
    char c = board[x][y];
    board[x][y] = '.';
    bool res = startsHere(board, x+1, y, word, idx+1) ||
               startsHere(board, x-1, y, word, idx+1) ||
               startsHere(board, x, y+1, word, idx+1) ||
               startsHere(board, x, y-1, word, idx+1);
    board[x][y] = c;
    return res;
}
bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (startsHere(board, i, j, word, 0)) return true;
        }
    }
    return false;
}

// Question 2; Power(x,n)
double binaryExp(double x, long long n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 1.0 / binaryExp(x, -1 * n);
    }
    if (n % 2 == 1) {
        return x * binaryExp(x * x, (n - 1) / 2);
    } else {
        return binaryExp(x * x, n / 2);
    }
}
double myPow(double x, int n) {
    return binaryExp(x, (long long) n);
}

// Question 3: Power Set
// done in lecture9.cpp

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout<<exist(board, word)<<endl;
    cout<<endl;
    
    cout<<myPow(2.00000, 10)<<endl;
    cout<<endl;
    
    return 0;
}
