#include<bits/stdc++.h>
using namespace std;

// Question 1: Rat in a maze
void solve(int i, int j, vector<vector<int>>& m, int n, vector<vector<bool>> dp, string s, vector<string>& v) {
    if(i == n-1 && j == n-1) {
        v.push_back(s);
        return;
    }
    if(i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0) return;
    if(dp[i][j] == true) return;
    dp[i][j] = true;
    solve(i+1, j, m, n, dp, s+'D', v);
    solve(i, j+1, m, n, dp, s+'R', v);
    solve(i-1, j, m, n, dp, s+'U', v);
    solve(i, j-1, m, n, dp, s+'L', v);
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> v;
    if(m[n-1][n-1] == 0) {
        v.push_back("-1");
        return v;
    }
    string s;
    vector<vector<bool>> dp(n, vector<bool> (n, false));
    solve(0, 0, m, n, dp, s, v);
    return v;
}

// Question 2: Unique Path 3
int res = 0, emp = 1;
void dfs(vector<vector<int>>& grid, int x, int y, int count) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) return;
    if (grid[x][y] == 2) {
        if(emp == count) res++; 
        return;
    }
    grid[x][y] = -1;
    dfs(grid, x+1, y, count+1);
    dfs(grid, x-1, y, count+1);
    dfs(grid, x, y+1, count+1);
    dfs(grid, x, y-1, count+1);
    grid[x][y] = 0;
}
    
int uniquePathsIII(vector<vector<int>>& grid) {
    int start_x, start_y;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) start_x = i, start_y = j;
            else if (grid[i][j] == 0) emp++;
        }
    }
    dfs(grid, start_x, start_y, 0);
    return res;
}

// Question 3: N Queens
bool validposition(vector<string> & CB, vector<int> &ldiag, vector<int> &rdiag, vector<int> &coltop, int n, int row, vector<vector<string> > &ans){
	if(row == n){
		ans.push_back(CB);
		return false;
	}
	for(int j = 0; j<n; j++){
		if(ldiag[n+row-j] || rdiag[row+j] || coltop[j])
			continue;
		ldiag[n+row-j] = rdiag[row+j] = coltop[j] = 1, CB[row][j] = 'Q';
		if(validposition(CB,ldiag, rdiag, coltop, n, row+1, ans))
			return true;
		else
			ldiag[n+row-j] = rdiag[row+j] = coltop[j] = 0, CB[row][j] = '.';
	}
	return false;
}
vector<vector<string>> solveNQueens(int n) {
	string init = "";
	for(int i =0; i<n; i++)
		init += '.';
	vector<string> CB (n, init);
	vector<int> ldiag(2*n, 0), rdiag(2*n, 0), coltop(n, 0);
	vector<vector<string> > ans;
	validposition(CB, ldiag, rdiag, coltop, n, 0, ans);
	return ans;
}

int main() {
    vector<vector<int>> m = {{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
    int n = 4;
    vector<string> res = findPath(m, n);
    for(auto it : res) {
        cout<<it<<endl;
    }
    cout<<endl;
    
    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    cout<<uniquePathsIII(grid)<<endl;
    cout<<endl;
    
    vector<vector<string>> res1 = solveNQueens(4);
    for(auto it : res1) {
        for(auto i : it) {
            cout<<i<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}
